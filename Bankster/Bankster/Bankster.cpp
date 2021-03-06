// Bankster.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <string>

using namespace std;

const int INF = INT_MAX;

enum color {
	white,
	gray,
	black
};


typedef struct Node {
	int val, dist;
	color clr;
	vector <pair<Node *, int>> neighbours;
	Node *parent;
} Node;

Node *newNode(int val) {
	Node *n = new Node;
	n->val = val;
	n->dist = INF;
	n->parent = NULL;
	n->clr = white;
	return n;
}


void addEdge(Node *u, Node *v, int w) {
	pair <Node *, int> edge(v, w);
	u->neighbours.push_back(edge);
}
/*
5 7   
0 1 20   
0 2 50  
0 4 1  
2 1 -10  
4 2 1  
3 0 1000   
4 3 1
0 1
*/

bool relax(Node *u, Node *v, int weight) {
	if (v->clr == gray) return false;
	v->clr = gray;
	if (v->dist > weight) {
		v->dist = weight;
		v->parent = u;
		for (unsigned int i = 0; i < v->neighbours.size(); i++) {
			if (!relax(v, v->neighbours[i].first, weight + v->neighbours[i].second)) {
				v->clr = black;
				return false;
			}
		}
	}
	v->clr = black;
	return true;
}

bool bellmann_ford(Node **nodes, int n, Node *start) {
	int weight = 0;
	start->dist = weight;
	start->clr = gray;
	for (unsigned int i = 0; i < start->neighbours.size(); i++) {
		weight = start->dist;
		if (!relax(start, start->neighbours[i].first, weight + start->neighbours[i].second)) return false;

	}

	return true;
}

int main() {
	int N, k, start, end;
	cin >> N >> k;
	Node **nodes = new Node*[N];
	for (int i = 0; i < N; i++) nodes[i] = newNode(i);

	for (int i = 0; i < k; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(nodes[u], nodes[v], w);
	}

	cin >> start >> end;
	if (!bellmann_ford(nodes, N, nodes[start])) cout << "CYKL" << endl;
	else 
		if (nodes[end]->dist < INF) cout << nodes[end]->dist << endl;
	else cout << "NIE" << endl;

	for (int i = 0; i<N; i++) delete nodes[i];
}