#include <bits/stdc++.h>
using namespace std;

#define MAX_NODES 6

int graph[MAX_NODES][MAX_NODES];
char color[MAX_NODES];
int level[MAX_NODES];
int parent[MAX_NODES];

int main()
{
    int edgeCount;
    cout << "Enter the number of edges: ";
    cin >> edgeCount;

    cout << "Enter the edges (u v) in the graph: " << endl;
    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
    }

    int sourceNode;
    cout << "Enter the source node: ";
    cin >> sourceNode;

    //step-1
    for (int i = 0; i < MAX_NODES; ++i) {
        color[i] = 'w';
        level[i] = 99999999;
        parent[i] = -1;
    }

    //step-2
    int queue[MAX_NODES];
    int start, end;
    start = 0;
    end = 0;
    queue[end] = sourceNode;
    end++;
    color[sourceNode] = 'g';
    level[sourceNode] = 0;
    parent[sourceNode] = -1;


    while (end - start > 0) {
        int u = queue[start];
        for (int i = 0; i < MAX_NODES; ++i) {
            int v = i;

            if (graph[u][v] == 1 && color[v] == 'w') {
                queue[end] = v;
                end++;
                color[v] = 'g';
                level[v] = level[u] + 1;
                parent[v] = u;
            }
        }
        start++;
        color[u] = 'b';
    }

    cout << "Level, Parent and Color of each node:" << endl;
    for (int i = 0; i < MAX_NODES; ++i) {
        cout << "Level[" << i << "] = " << level[i] << endl;
        cout << "Parent[" << i << "] = " << parent[i] << endl;
        cout << "Color[" << i << "] = " << color[i] << endl;
        cout << endl;
    }

    return 0;
}
