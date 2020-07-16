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

int find (int x, int* parent)
{
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
}

void unia (int x, int y, int* parent, int* rank)
{
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
}

int draught_calculator(int **map, int n, int k) {
    return 0;
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
}

auto cmp = [](int x, int y) { return x < y };

void dijkstra(Node **nodes, int n, Node *start) {
	priority_queue <Node *, vector<Node *>, decltype(cmp)> queue(cmp);
	int weight = 0;
	edge start;  start.x = 0; start.y = 0;
	edge end; end.x = n; end.y = n;
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

int main ()
{
    int Z;
    scanf("%d", &Z);
    while(Z--)
    {
        int n, k;
        scanf ("%d %d", &n, &k);
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

        printf ("%d\n", result);

        for (int i = 0; i < n; i++)
            delete[] map[i];
        delete[] map;

    }
}
