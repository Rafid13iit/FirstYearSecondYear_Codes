#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 7

int graph[MAX_SIZE][MAX_SIZE];
char color[MAX_SIZE];
int parent[MAX_SIZE];

void DFS(int node) {
    cout << "Visiting node " << node << endl;
    cout << "Parent array: [ ";
    for (int i = 0; i < MAX_SIZE; ++i) {
        cout << parent[i] << " ";
    }
    cout << "]" << endl;
    cout << "Color array: [ ";
    for (int i = 0; i < MAX_SIZE; ++i) {
        cout << color[i] << " ";
    }
    cout << "]" << endl;
    cout << "-----------------------------------------------" << endl;

    color[node] = 'g';
    for (int i = 0; i < MAX_SIZE; ++i) {
        int adj = i;
        if (graph[node][adj] == 1 and color[adj] == 'w') {
            parent[adj] = node;
            DFS(adj);
        }
    }
    color[node] = 'b';
}

int main()
{
    int edge_count;
    cout << "Enter the number of edges in the graph: ";
    cin >> edge_count;

    cout << "Enter the edges in the format 'u v': " << endl;
    for (int i = 0; i < edge_count; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
    }

    for (int i = 0; i < MAX_SIZE; ++i) {
        color[i] = 'w';
        parent[i] = -1;
    }

    int source_node;
    cout << "Enter the source node: ";
    cin >> source_node;

    DFS(source_node);
    parent[source_node] = -1;

    cout << "Final parent array: [ ";
    for (int i = 0; i < MAX_SIZE; ++i) {
        cout << parent[i] << " ";
    }
    cout << "]" << endl;
    cout << "Final color array: [ ";
    for (int i = 0; i < MAX_SIZE; ++i) {
        cout << color[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}
