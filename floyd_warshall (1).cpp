#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX / 2;

typedef struct Segment {
    int town, travel_time;
} Segment;

typedef struct Line {
    Segment* segments;
    int number, length, start_town;
} Line;

Line* newLine(int number, int length, int start_town) {
    Line* l = new Line;
    l->number = number;
    l->length = length;
    l->start_town = start_town;
    l->segments = new Segment[length];
    return l;
}
  
/*
typedef struct Node {
    int town, id;
    vector< pair<Node*, int> > neighbours;
} Node;
bool relax(Node *u, Node *v, int weight) {
	if (v->clr == gray || v->val == 0) return false;
	v->clr = gray;
	if (v->dist > weight) {
		v->dist = weight;
		v->parent = u;
		for (unsigned int i = 0; i < v->neighbours.size(); i++) {
			if (!relax(v, v->neighbours[i].first, weight + v->neighbours[i].second)) return false;
		}
	}
	v->clr = black;
}





bool relax(Node *u, Node *v, int weight) {
if (v->dist > weight) {
v->dist = weight;
for (unsigned int i = 0; i < towns ; i++) {
if ( ) {
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
for (unsigned int i = 0; i < start->neighbours.size(); i++) {
weight = start->dist;
if (!relax(start, start->neighbours[i].first, weight + start->neighbours[i].second)) return false;

}

return true;
}
*/

int** calculateTimesMatrix(Line** lines, int lines_no, int towns) {
	int** times = new int*[towns];
	bool *visited = new bool[towns];
	for (int i = 0; i < towns; i++) {
		times[i] = new int[towns];
		visited = false;
		for (int j = 0; j < towns; j++) {
			times[i][j] = INF;
		}
	}
	for (int i = 0; i < lines_no; i++) {
		Segment *u = lines[i]->start_town;
		int time = 0;
		for (int j = 0; j < lines[i]->length; j++) {
			Segment* v = lines[i]->segments[j];
			time = v->travel_time;
			if (times[u->town][v->town] > time) times[u->town][v->town] = time;
			if (times[v->town][u->town] > time) times[v->town][u->town] = time;
		}
	}
	for (int i = 0; i < towns; i++) {
		int weight = 0;
		times[i][i] = weight;
		for (int j = 0; j < towns; j++) {
			visited = false;
		}
		for (int j = 0; j < towns; j++) {
			DFSVisit(times, visited, towns, i, j, times[i][j]);
		}
	}
	return times;
}

void DFSVisit(int **times, bool* visited, int towns, int u, int v, int time) {
	for (int i = 0; i < towns; i++) {
		if (!visited[i] || times[u][i] > time + times[v][i]) {
			visited[i] = true;
			times[u][i] = time + times[v][i];
			DFSVisit(times, visited, towns, v, i, time+times[v][i]);
	}
}

int main() {
    int towns, lines_no, queries;
    cin >> towns >> lines_no >> queries;
    Line** lines = new Line*[lines_no];
    for (int i=0; i<lines_no; i++) {
        int len, start;
        cin >> len >> start;
        lines[i] = newLine(i, len-1, start);
        for (int j=0; j<len-1; j++) {
            int next, time;
            cin >> time >> next;
            lines[i]->segments[j].town = next;
            lines[i]->segments[j].travel_time = time;
        }
    }

    int** times = calculateTimesMatrix(lines, lines_no, towns);

    for (int i=0; i<queries; i++) {
        int u, v;
        cin >> u >> v;
        cout << times[u][v] << endl;
    }

    for (int i=0; i<towns; i++) delete[] times[i];
    delete[] times;
    for (int i=0; i<lines_no; i++) {
        delete[] lines[i]->segments;
        delete lines[i];
    }
    delete[] lines;
}