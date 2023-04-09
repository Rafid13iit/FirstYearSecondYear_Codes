#include <bits/stdc++.h>
using namespace std;

#define MAX 100

//structure can be used here
int vertex, edge;
int graph_G[MAX][MAX];
int cost[MAX][MAX];


void printSolution(int src, int dst, int distance[][MAX])
{
    if (distance[src][dst] == INT_MAX) {
        cout << "There is no path from vertex " << src << " to vertex " << dst << endl;
    }

    else{
        cout << "SoureVertex \t DestinationVertex \t Distance from Source" << endl;
        cout << "     " << src << " \t\t\t" << dst << " \t\t\t" << distance[src][dst] << endl;
    }
}


void floydWarshall(int src, int dst)
{
    int distance[MAX][MAX];

    for (int i = 0; i < vertex; i++){
        for (int j = 0; j < vertex; j++){
            distance[i][j] = INT_MAX;

            if (i == j){
                distance[i][j] = 0;
            }
        }  
    }


    for (int k = 0; k < vertex; k++){

        for (int i = 0; i < vertex; i++){
            for (int j = 0; j < vertex; j++){

                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
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
	floydWarshall(src, dst);


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

4
6
0 1 1
0 2 -2
1 0 4
1 2 3
2 3 2
3 0 5
3 1

the answer will be 6 for this case

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