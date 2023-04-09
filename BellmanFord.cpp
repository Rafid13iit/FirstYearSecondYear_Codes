#include <bits/stdc++.h>
using namespace std;

#define MAX 100

//structure can be used here
int vertex, edge;
int graph_G[MAX][MAX];
int cost[MAX][MAX];


void printSolution(int src, int dst, int distance[])
{
    if (distance[dst] == INT_MAX) {
        cout << "There is no path from vertex " << src << " to vertex " << dst << endl;
    }

    else{
        cout << "SoureVertex \t DestinationVertex \t Distance from Source" << endl;
        cout << "     " << src << " \t\t\t" << dst << " \t\t\t" << distance[dst] << endl;
    }
}


void bellmanFord(int src, int dst)
{
	int distance[vertex];

	// Initializes all distances as INFINITE
	for (int i = 0; i < vertex; i++){
		distance[i] = INT_MAX;
    }

	// Distance of source vertex from itself is always 0
	distance[src] = 0;

    for (int count = 1; count <= vertex-1; count++){

        // Updating distance value of the adjacent vertices of the picked vertex.
        for (int u = 0; u < vertex; u++) {
            for (int v = 0; v < vertex; v++){

                if ((graph_G[u][v] != -1) && (distance[u] != INT_MAX) && (distance[u] + cost[u][v] < distance[v])){
                    
                    distance[v] = distance[u] + cost[u][v];
                }
            }
        }

    }


    // Step 3: check for negative-weight cycles.  The above
    // step guarantees shortest distances if graph doesn't
    // contain negative weight cycle.  If we get a shorter
    // path, then there is a cycle.
    for (int u = 0; u < vertex; u++) {
		for (int v = 0; v < vertex; v++){

			if ((graph_G[u][v] != -1) && (distance[u] != INT_MAX) && (distance[u] + cost[u][v] < distance[v])){
				
                cout << "Graph contains negative weight cycle!" << endl;
                return ; // If negative cycle is detected, simply returned
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

	// Function call
	bellmanFord(src, dst);


	return 0;
}

/*
example-1:

6
9
0 1 6
0 2 4
0 3 5
1 4 -1
2 1 -2
2 4 3
3 2 -2
3 5 -1
4 5 3
0 5

the answer will be 3 for this case

example-2:

5
8
0 1 -1
0 2 4
1 4 2
1 3 2
1 2 3
3 1 1
3 2 5
4 3 -3
0 3

the answer will be -2 for this case

example-3 (Cycle in Graph):

4
5
0 1 1
0 2 2
1 2 2
2 3 2
3 1 -5
0 3

cycle in the graph
*/