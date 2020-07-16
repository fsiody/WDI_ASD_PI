// swim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <queue>
#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <queue>
#define DEBUG 1

using namespace std;

struct edge
{
	int x, y;
	int s;
};

bool operator< (edge a, edge b)
{
	if (a.s < b.s)
		return true;
	else
		return false;
}

void print_map(int **map, int n) {
#ifdef DEBUG
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
#endif
}

int find(int x, int* parent)
{
	/**********************
	* PLACE FOR YOUR CODE *
	**********************/
}

void unia(int x, int y, int* parent, int* rank)
{
	/**********************
	* PLACE FOR YOUR CODE *
	**********************/
}

int find(int x, int* parent)
{
	return parent[x];
}

void Union(int x, int y, int* parent, int n)
{
	int rx = find(x, parent);
	int ry = find(y, parent);
	if (rx != ry) {
		for (int i = 0; i <= n + 1; i++) {
			if (parent[i] == ry) {
				parent[i] = rx;
			}
		}
	}
}




int draught_calculator(int **map, int n, int k) {
	priority_queue <edge> Q;
	int weight = INFINITY;
	edge start;  start.x = 0; start.y = 0;
	edge end; end.x = n - 1; end.y = n - 1;
	int road = 0;
	Q.push(start);
	while (!Q.empty()) {
		edge u = Q.top();
		Q.pop();
		q
			edge ng[4];
		ng[0].x = u.x; ng[1].x = u.x; ng[2].x = u.x - 1; ng[3].x = u.x + 1;
		ng[0].y = u.y - 1; ng[1].y = u.y + 1; ng[2].y = u.y; ng[3].y = u.y;
		for (int i = 0; i < 4; i++) {
			if (ng[i].x < 0 || ng[i].x >= n || ng[i].s < 0 || ng[i].y < 0 || ng[i].y >= n) {}
			else Q.push(ng[i]);


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
	int Z;
	scanf("%d", &Z);
	while (Z--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		int **map = new int*[n];
		for (int i = 0; i < n; i++)
			map[i] = new int[n];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		print_map(map, n);

		int result = draught_calculator(map, n, k);

		printf("%d\n", result);

		for (int i = 0; i < n; i++)
			delete[] map[i];
		delete[] map;

	}
}