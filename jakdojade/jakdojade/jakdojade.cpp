// jakdojade.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX / 2;

typedef struct Segment {
	int town, travel_time;
} Segment;

typedef struct Line {
	Segment* segments;
	int number, length, start_town;
} Line;

Line* newLine(int number, int length, int start_town) {
	Line* l = new Line;
	l->number = number;
	l->length = length;
	l->start_town = start_town;
	l->segments = new Segment[length];
	return l;
}


void DFSVisit(int **&times, bool *&visited, int towns, int u, int v, int time) {
	for (int i = 0; i < towns; i++) {
		if (!visited[i] && times[u][i] > time + times[v][i]) {
			visited[i] = true;
			if (times[i][u] < time + times[v][i]) times[u][i] = times[i][u];
			else {
				times[u][i] = time + times[v][i];
				times[i][u] = time + times[v][i];
			}
			DFSVisit(times, visited, towns, u, i, time + times[v][i]);
		}
	//	visited[i] = true;
	}
}

int** calculateTimesMatrix(Line** lines, int lines_no, int towns) {
	int** times = new int*[towns];
	bool* visited = new bool [towns];
	for (int i = 0; i < towns; i++) {
		times[i] = new int[towns];
		visited[i] = false;
		for (int j = 0; j < towns; j++) {
			times[i][j] = INF;
		}
	}
	for (int i = 0; i < lines_no; i++) {
		int u = lines[i]->start_town;
		int time = 0;
		times[u][u] = 0;
		for (int j = 0; j < lines[i]->length; j++) {
			int v = lines[i]->segments[j].town;
			time = lines[i]->segments[j].travel_time;
			if (times[u][v] > time) times[u][v] = time;
			if (times[v][u] > time) times[v][u] = time;
			u = v;
		}
	}
	for (int i = 0; i < towns; i++) {
		int weight = 0;
		times[i][i] = weight;
		for (int j = 0; j < towns; j++) visited[j] = false;
		for (int j = 0; j < towns; j++) {
			DFSVisit(times, visited, towns, i, j, times[i][j]);
		}
	}
	for (int i = 0; i < towns; i++) {
		int weight = 0;
		times[i][i] = weight;
		for (int j = 0; j < towns; j++) visited[j] = false;
		for (int j = towns-1; j >=0; j--) {
			DFSVisit(times, visited, towns, i, j, times[i][j]);
		}
	}
	for (int i = 0; i < towns; i++) {
		int weight = 0;
		times[i][i] = weight;
		for (int j = 0; j < towns; j++) visited[j] = false;
		for (int j = 0; j < towns; j++) {
			DFSVisit(times, visited, towns, i, j, times[i][j]);
		}
	}
	return times;
}

/*
6 2 3  
3   
4    1 1    1 3 
4  
5    1 0    1 1    1 2
  3 1
  4 2
  4 3





  14 3 5
  5   1   1 2   1 3   1 4   1 5
  6   0   1  13   1 3    1 12     1 9    1 11
  6   6   1  7     1 4   1  8     1 9     1 10
*/

	int main() {
		int towns, lines_no, queries;
		cin >> towns >> lines_no >> queries;
		Line** lines = new Line*[lines_no];
		for (int i = 0; i<lines_no; i++) {
			int len, start;
			cin >> len >> start;
			lines[i] = newLine(i, len - 1, start);
			for (int j = 0; j<len - 1; j++) {
				int next, time;
				cin >> time >> next;
				lines[i]->segments[j].town = next;
				lines[i]->segments[j].travel_time = time;
			}
		}

		int** times = calculateTimesMatrix(lines, lines_no, towns);
		
		for (int i = 0; i < towns; i++) {
			cout << endl;
			for (int j = 0; j < towns; j++) {
				cout << times[i][j] << "  ";
			}
		}



		for (int i = 0; i<queries; i++) {
			int u, v;
			cin >> u >> v;
			cout << times[u][v] << endl;
		}

		for (int i = 0; i<towns; i++) delete[] times[i];
		delete[] times;
		for (int i = 0; i<lines_no; i++) {
			delete[] lines[i]->segments;
			delete lines[i];
		}
		delete[] lines;
	}