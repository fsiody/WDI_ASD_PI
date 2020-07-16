#include <cstdio>
#include <queue>

using namespace std;
 
struct edge 
 { 
	int u, v; 
	int s; 
}; 
 
bool operator< (edge a, edge b) 
{ 
	if (a.s > b.s) 
		return true; 
	else 
		return false; 
} 
 
 
int Find(int x, int* parent) 
{ 
	if (parent[x] == x) return x; 
	else {
		return parent[x] = Find(parent[x], parent);
	}
} 
 
bool Union(int x, int y, int* parent) 
{ 
	x = Find(x,parent);
	y = Find(y,parent);
	if (x == y) {
		return false;
	}
	parent[x] = y; 
	return true; 
} 
 
unsigned long long mst(priority_queue<edge> Q, int n) 
{ 
	unsigned long long cost = 0; 
	int *parent = new int[n + 1]; 
	 
	for (int i = 0; i <= n; i++) parent[i] = i; 
	 
	while (!Q.empty()){
		edge tmp = Q.top(); 
		Q.pop();
		if (Union(tmp.u, tmp.v, parent)) {
			cost += tmp.s;
		}
	}
	return cost; 
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
			temp.u = u; 
			temp.v = v; 
			temp.s = s; 
			Q.push(temp);
		}

		unsigned long long cost = mst(Q, n);

		printf("%llu\n", cost);
	}
}