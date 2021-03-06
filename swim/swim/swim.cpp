
#include "stdafx.h"
#include <cstdio>
#include <queue>
#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <queue>
#include <cstdio>
#include <queue>
#define DEBUG 1

using namespace std;

struct edge
{
	int x, y;
	int s;
	color clr;
	edge *parent;
	edge **ng[4];
};

enum color {
	white,
	gray,
	black
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
	return 0;
}

void unia(int x, int y, int* parent, int* rank)
{
	/**********************
	* PLACE FOR YOUR CODE *
	**********************/
}


bool relax(int **map, edge u, edge v, int weight, int n) {
	if (v.clr == gray) return false;
	v.clr = gray;
	if (v.s < weight) {
		v.s = weight;
		
		edge ng[4];
		ng[0].x = u.x; ng[1].x = u.x; ng[2].x = u.x - 1; ng[3].x = u.x + 1;
		ng[0].y = u.y - 1; ng[1].y = u.y + 1; ng[2].y = u.y; ng[3].y = u.y;
		for (int i = 0; i < 4; i++) {
			if (ng[i].x < 0 || ng[i].x >= n || ng[i].s < 0 || ng[i].y < 0 || ng[i].y >= n) {}
			else 

		
		
		
		for (unsigned int i = 0; i < n; i++) {
			if (!relax(map, v,e, weight, n);
				nd)) {
				v->clr = black;
				return false;
			}
		}
	}
	v->clr = black;

}

int draught_calculator(int **map, int n, int k) {
	int weight = 0;




	
	priority_queue <edge> Q;
	edge start;  start.x = 0; start.y = 0;
	edge end; end.x = n - 1; end.y = n - 1;
	Q.push(start);
	while (!Q.empty()) {
		edge u = Q.top();
		if (u.s < weight) u.s = weight;
		Q.pop();
		edge ng[4];
		ng[0].x = u.x; ng[1].x = u.x; ng[2].x = u.x - 1; ng[3].x = u.x + 1;
		ng[0].y = u.y - 1; ng[1].y = u.y + 1; ng[2].y = u.y; ng[3].y = u.y;
		for (int i = 0; i < 4; i++) {
			if (ng[i].x < 0 || ng[i].x >= n || ng[i].s < 0 || ng[i].y < 0 || ng[i].y >= n) {}
			else {
				if (ng[i].s > weight) weight = ng[i].s;
				Q.push(ng[i]);
			}
		}

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

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = max(0, k - map[i][j]);
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
