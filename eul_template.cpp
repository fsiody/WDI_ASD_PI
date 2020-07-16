#include <stdio.h>
// we're big guys now, let's use already implemeted list
// you might want check this out: http://www.cplusplus.com/reference/list/list/#functions
#include <list>

using namespace std;

enum graph_type {
    EULER = 1,
    HALF = 2,
    NO = 3
};

graph_type check_graph(list<int> graph[], int n) {
	int nieparzyste = 0;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
	while (!graph->empty()) {
		a[graph->back()]++;
		graph->pop_back();
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % != 0)nieparzyste++;
	}

    if ( nieparzyste==0 ) {
        return EULER;
    } else if ( nieparzyste<3 ) {
        return HALF;
    } else {
        return NO;
    }
}

int main() {
    int Z;

    scanf("%d", &Z);

    while (Z--) {

        int n, m;
        int u, v;
        scanf("%d %d", &n, &m);
        list<int> *graph = new list<int>[n+1];
        for(int i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        graph_type result = check_graph(graph, n);
        switch(result) {
            case EULER:
                printf("EULER\n");
                break;
            case HALF:
                printf("HALF\n");
                break;
            case NO:
                printf("NO\n");
                break;
        }
        delete [] graph;
    }
}
