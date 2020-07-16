// dijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT_MAX;

typedef struct Node {
	int val, dist;
	vector <pair<Node *, int>> neighbours;
	Node *parent;
} Node;

Node *newNode(int val) {
	Node *n = new Node;
	n->val = val;
	n->dist = INF;
	n->parent = NULL;
	return n;
}

void addEdge(Node *u, Node *v, int w) {
	pair <Node *, int> u_edge(v, w);
	pair <Node *, int> v_edge(u, w);
	u->neighbours.push_back(u_edge);
	v->neighbours.push_back(v_edge);
}

auto cmp = [](Node *x, Node *y) { return x->dist > y->dist; };

//bool relax(Node *u, Node *v, int weight)

void dijkstra(Node **nodes, int n, Node *start) {
	priority_queue <Node *, vector<Node *>, decltype(cmp)> queue(cmp);
	int weight = 0;
	start->dist = weight;
	int road = 0;
	queue.push(start);
	while (!queue.empty()) {
		Node* u = queue.top();
		queue.pop();
		for (int i = 0; i < u->neighbours.size(); i++) {
			weight = u->dist;
			if (u->neighbours[i].first->dist > weight + u->neighbours[i].second) {
				u->neighbours[i].first->dist = weight + u->neighbours[i].second;
				u->neighbours[i].first->parent = u;
				queue.push(u->neighbours[i].first);
			}
		}
	}
}

int main()
{
	int N, k, start, end;
	cin >> N >> k;
	Node **nodes = new Node*[N];
	for (int i = 0; i < N; i++) nodes[i] = newNode(i);
	/*
	0 1 3
	0 4 6
	1 2 1
	1 3 9
	2 3 1
	3 4 9
	*/
	for (int i = 0; i < k; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(nodes[u], nodes[v], w);
	}

	cin >> start >> end;
	dijkstra(nodes, N, nodes[start]);
	cout << nodes[end]->dist << endl;

	for (int i = 0; i<N; i++) delete nodes[i];
	return 0;
}

