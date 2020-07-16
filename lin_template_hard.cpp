#include <stdio.h>
#include <list>

using namespace std;

int n;
list<int> *graph;
int curr_line;
list<int> *lines;
bool is_euler;


void euler(int u)
{
  /*  while (!graph[u].empty())
    {
        int v = // take first neighbour of u


        // iterate over neighbours of v
        // you can use list<int>::iterator it = graph[v].begin()
        // which makes "it" iterator (sth like pointer) pointing on first element of graph[v] list
        // iterator can be moved to next position like this: it++
        // and if you move it after last element of list it will be equal to graph[v].end()
        for ()
        {
            // if you find u remove it from list
            // you can access element pointed by iterator just like with pointer
            if ()
            {
                // use erase method
            }
        }

        // recursively enter v
    }*/


	while (!graph[u].empty())
	{
		int v = graph[u].front();// take first neighbour of u
		graph[u].pop_front();

		// iterate over neighbours of v
		// you can use list<int>::iterator it = graph[v].begin()
		// which makes "it" iterator (sth like pointer) pointing on first element of graph[v] list
		// iterator can be moved to next position like this: it++
		// and if you move it after last element of list it will be equal to graph[v].end()
		list<int>::iterator it = graph[v].begin();
		while (it != graph[v].end())
		{
			if (*it == u)// if you find u remove it from list
			{
				list<int>::iterator tmp = it;// you can access element pointed by iterator just like with pointer
				it++;
				graph[v].erase(tmp); // use erase method
			}
			else it++;
		}
		euler(v); // recursively enter v
	}
    // if we're visiting our dummy city, start a new line
    if (!is_euler && u==n+1) {
		curr_line++;
    } else {
		lines[curr_line]->push_front(u);
        // if not, just add city to current line
    }

}

int main() {
    int Z;

    scanf("%d", &Z);

    while (Z--) {
        int m, u, v;
        scanf("%d %d", &n, &m);

        graph = new list<int>[n+2];
        lines = new list<int>[n+2];

        for(int i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        is_euler = true;
		int niep = 0;
        for (int i = 1; i <= n; i++)
        {
            // add dummy city to each city that has odd number of neighbours

            if (graph[i].size() % 2 != 0)
            {
				graph[i].push_back(n + 1);
                is_euler = false;
            }
        }

        curr_line = 0;

        if (is_euler) {
			euler(1);
        } else {
			euler(n + 1);
        }

        // ignore empty lines
        int lines_number = 0;
        for (int i = 0; i <= curr_line; i++)
        {
            if (lines[i].size()>1)
                lines_number++;
        }

        printf("%d\n", lines_number);

        for (int i = 0; i <= lines_number; i++)
        {
            if (lines[i].size() > 1)
            {

				lines[i].pop_back();
                printf("%lu ", lines[i].size());
                for (list<int>::iterator it = lines[i].begin(); it != lines[i].end(); it++)
                {
                    printf("%d ", *it);
                }
                printf("\n");
            }
        }

        delete[] graph;
        delete[] lines;
    }
}
