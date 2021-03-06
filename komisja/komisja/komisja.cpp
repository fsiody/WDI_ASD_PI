// komisja.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node {
	int n;
	struct Node* next;
} Node;

enum color {
	white,
	gray,
	black
};

bool find_cycle_from(Node** graph, color* visited, int n, int x) {
	visited[x] = gray;
	Node *tmp = graph[x];
	while (tmp!=NULL) {
		if (visited[tmp->n] == gray) return true;
		if (find_cycle_from(graph, visited, n, tmp->n)) return true;
		tmp = tmp->next;
	}
	visited[x] = black;
	return false;
}

bool has_cycle(Node** graph, int n) {
	color *visited=new color[n];
	for (int i = 0; i<n; i++) visited[i] = white;
	for (int i = 0; i<n; i++) {
		if (visited[i] == white) {
			if (find_cycle_from(graph, visited, n, i)) return true;
		}
	}
	return false;
}

int main() {
	int n, k;
	cin >> n;
	Node **graph = new Node*[n];
	cin >> k;
	for (int i = 0; i < n; i++) graph[i] = NULL;
	for (int i = 0; i<k; i++) {
		Node* tmp = new Node;
		int x, y;
		cin >> x;
		cin >> y;
		tmp->n = y;
		tmp->next = graph[x];
		graph[x] = tmp;
	}
	cout << (has_cycle(graph, n) ? "CYKL" : "OK") << endl;
}