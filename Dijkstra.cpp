#include <bits/stdc++.h>
using namespace std;

#define MAX 100

//structure can be used here
int vertex, edge;
int graph_G[MAX][MAX];
int cost[MAX][MAX];

//finds the vertex with minimum distance value,
//from the set of vertices not yet included in shortest path tree
int minDistance(int distance[], bool sptSet[])
{

	// Initialize min value
	int min = INT_MAX;
    int min_index = -1;

	for (int i = 0; i < vertex; i++){
		if (sptSet[i] == false && distance[i] <= min){
			min = distance[i];
            min_index = i;
        }
    }

	return min_index;
}

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


void dijkstra(int src, int dst)
{
	int distance[vertex];

	bool sptSet[vertex]; //shortest path tree set

	// Initializes all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < vertex; i++){
		distance[i] = INT_MAX;
        sptSet[i] = false;
    }

	// Distance of source vertex from itself is always 0
	distance[src] = 0;

    // it finds shortest path for all vertices
    for (int count = 0; count < vertex-1; count++) {

	    int u = minDistance(distance, sptSet);

		// Marking the picked vertex as processed
		sptSet[u] = true;

		// Updating distance value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < vertex; v++){

			if (!sptSet[v] && (graph_G[u][v] != -1) && (distance[u] != INT_MAX) && (distance[u] + cost[u][v] < distance[v])){
				
                distance[v] = distance[u] + cost[u][v];
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

        graph_G[u][v] = graph_G[v][u] = 1;
        cost[u][v] = cost[v][u] = w;
    }

    int src, dst;

    cout << "Enter source and destination vertex : ";
    cin >> src >> dst;

	// Function call
	dijkstra(src, dst);


	return 0;
}

/*
6
9
0 1 14
0 2 9
0 5 7
1 3 8
1 2 2
2 4 11
2 5 10
3 4 6
4 5 15
0 4

the answer will be 20 for this case
*/
