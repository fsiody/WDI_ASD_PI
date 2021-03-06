// min_tree_hyperloop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdio>
#include <queue>

using namespace std;

struct edge
{
	int u, v;
	int s;
};

// this is called operator overload
// we can now use operator < with edges
// priority_queue<edge> will also use this operator to sort edges
bool operator< (edge a, edge b)
{
	if (a.s > b.s)
		return true;
	else
		return false;
}

int find(int x, int* parent)
{
	return parent[x];
}

void Union (int x, int y, int* parent,int n)
{
	int rx = find(x, parent);
	int ry = find(y, parent);
	if (rx != ry) {
		for (int i = 0; i<=n+1; i++) {
			if (parent[i] == ry) {
				parent[i] = rx;
			}
		}
	}
}

/*

1   
4 5   
1 2 5   
2 3 6   
3 4 7    
4 1 8    
1 3 1    

]

1  
9 14  
1 2 4    1 8 8    2 3 8   2 8 11     3 4 7     3 6 4    3 9 2    9 7 6    8 7 1    7 6 2   6 5 10    4 6 14   4 5 9    8 9 7

*/



unsigned long long mst(priority_queue<edge> Q, int n)
{
	unsigned long long cost = 0;
	int *parent = new int[n + 1];

	for (int i = 0; i <= n+1; i++) {
		parent[i] = i;
	}
	parent[n + 1] = -1;
	edge e;
	int rx, ry;
	for (int i = 0; i < n; i++) {
		do {
			if (!Q.empty()) {
				e = Q.top();
				Q.pop();
				rx = find(e.u, parent);
				ry = find(e.v, parent);
			}
		} while (!Q.empty() && (rx == ry));
		if(rx != ry){
			cost += e.s;
			Union(e.u, e.v, parent,n);
		}
	}
	return cost;
	delete[] parent;
}

int main()
{
	int Z;
	scanf("%d", &Z);
	while (Z--)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		edge temp;
		int u, v, s;


		priority_queue<edge> Q;

		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &u, &v, &s);
			edge a;
			a.s = s;
			a.u = u;
			a.v = v;
			Q.push(a);
		}

		unsigned long long cost = mst(Q, n);

		printf("%llu\n", cost);
	}
	return 0;
}
