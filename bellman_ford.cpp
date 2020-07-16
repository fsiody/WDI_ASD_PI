#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int INF = INT_MAX;
queue <Node *, vector<Node *>> myqueue;

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
    pair <Node *, int> edge(v, w);
    u->neighbours.push_back(edge);
}

void relax(Node *u, Node *v, int weight) {

	if (v->dist > weight) {
		v->dist = weight;
		v->parent = u;
		myqueue.push(v);
	}


}

bool bellmann_ford(Node **nodes, int n, Node *start) {
	int weight = 0;
	start->dist = weight;
	int road = 0;
	myqueue.push(start);
	while (!queue.empty()) {
		Node* u = queue.top();
		queue.pop();
		for (int i = 0; i < u->neighbours.size(); i++) {
			weight = u->dist;
			relax(u, u->neighbours[i].first, weight + u->neighbours[i].second)

		}
	}

	return false;
}

int main() {
    int N, k, start, end;
    cin >> N >> k;
    Node *nodes[N];
    for (int i = 0; i < N; i++) nodes[i] = newNode(i);

    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(nodes[u], nodes[v], w);
    }

    cin >> start >> end;
    if (!bellmann_ford(nodes, N, nodes[start])) cout << "CYKL" << endl;
    else if (nodes[end]->dist < INF) cout << nodes[end]->dist << endl;
    else cout << "NIE" << endl;

    for(int i=0; i<N; i++) delete nodes[i];
}