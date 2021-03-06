// labirynt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

typedef struct point {
	int x, y;
} point;

typedef struct neighbours {
	int n;
	point elems[4];
} neighbours;

neighbours get_neighbours(int** labyrinth, int n, int m, point* p) {
	// find (if exist) all neighbours of point p
	neighbours np;
	if (p->y < m-1) {
		np.elems[0].y = p->y + 1;
		np.elems[0].x = p->x;
	}
	else {
		np.elems[0].y = -1;
		np.elems[0].x =-1;
	}


	if (p->y > 0) {
		np.elems[1].y = p->y - 1;
		np.elems[1].x = p->x;
	}
	else {
		np.elems[1].y = - 1;
		np.elems[1].x = -1;
	}


	if (p->x > 0) {
		np.elems[2].y = p->y;
		np.elems[2].x = p->x-1;
	}
	else {
		np.elems[2].y = -1;
		np.elems[2].x = -1;
	}


	if (p->x < n-1) {
		np.elems[3].y = p->y;
		np.elems[3].x = p->x+1;
	}
	else {
		np.elems[3].y = -1;
		np.elems[3].x = -1;
	}
	// (consider points: one above p, one below p, one on the left site and one on the right site)
	// use defined structures
	return np;
}

bool dfs(int** graph, int n, int m, bool** visited, point p, point end) {
	if (p.x == end.x && p.y == end.y) return true;
	visited[p.x][p.y] = false;
	neighbours np = get_neighbours(graph, n, m, &p);
	bool flag = false;
	for (int i = 0; i <= 3 && !flag; i++) {
		if (np.elems[i].x >= 0 && visited[np.elems[i].x][np.elems[i].y] && graph[np.elems[i].x][np.elems[i].y]>0 && !flag) flag= dfs(graph, n, m, visited, np.elems[i], end);
	}
	return flag;
}


int main() {
	int n, m;
	cin >> n;
	cin >> m;
	int **labyrinth = new int*[n];
	for (int i = 0; i<n; i++) labyrinth[i] = new int[m];
	bool** visited = new bool*[n];
	for (int i = 0; i < n; i++) {
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++) visited[i][j] = true;
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			cin >> labyrinth[i][j];
		}
	}
	point start, end;
	cin >> start.x;
	cin >> start.y;
	cin >> end.x;
	cin >> end.y;
	cout << (dfs(labyrinth, n, m, visited, start, end) ? "TAK" : "NIE") << endl;
}
