#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int vertex, edge;
int graph_G[MAX][MAX];
int cost[MAX][MAX];

void printSolution(int src, int dst, int distance[][MAX])
{
    if (distance[src][dst] == INT_MAX) {
        cout << "There is no path from vertex " << src << " to vertex " << dst << endl;
    }
    else{
        cout << "Source Vertex\tDestination Vertex\tDistance from Source" << endl;
        cout << "    " << src << " \t\t\t" << dst << " \t\t\t" << distance[src][dst] << endl;
    }
}

void floydWarshall(int src, int dst)
{
    int distance[MAX][MAX];

    // Initialize the distance matrix
    for (int i = 0; i < vertex; i++){
        for (int j = 0; j < vertex; j++){
            if (i == j){
                distance[i][j] = 0;
            }
            else if (graph_G[i][j] != -1){
                distance[i][j] = cost[i][j];
            }
            else{
                distance[i][j] = INT_MAX;
            }
        }  
    }

    // Compute the shortest distances
    for (int k = 0; k < vertex; k++){
        for (int i = 0; i < vertex; i++){
            for (int j = 0; j < vertex; j++){
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX){
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

    printSolution(src, dst, distance);
}

int main()
{
    cout << "Enter the number of vertices : ";
    cin >> vertex;
    cout << "Enter the number of edges : ";
    cin >> edge;

    int u, v, w;
    memset(cost, INT_MAX, sizeof(cost));
    memset(graph_G, -1, sizeof(graph_G));

    cout << "Enter edges (u to v) and its costs :" << endl;
    for (int i = 0; i < edge; i++){
        cin >> u >> v >> w;

        //Directed Graph
        graph_G[u][v] = 1;
        cost[u][v] = w;
    }

    int src, dst;
    cout << "Enter source and destination vertex : ";
    cin >> src >> dst;

    floydWarshall(src, dst);

    return 0;
}


/*
4
6
0 1 1
0 2 -2
1 0 4
1 2 3
2 3 2
3 0 5
2 0

the answer will be 7 for this case
*/