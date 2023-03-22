#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

ll nodes, edges;

ll selectMinVertex (vector<int>& value, vector<bool>& setMST)
{
	int minimum = INT_MAX;
	int vertex;
	
	for (int i = 0; i < nodes; i++)
	{
		if (setMST[i] == false && value[i] < minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	
	return vertex;
}

void findMST (int graph[nodes][nodes])
{
	int parent[nodes];
	vector<int> value (nodes, INT_MAX); //used edged relaxation
	vector<bool> setMST (nodes, false); //TRUE -> vertex is included in MST
	
	//Assuming start point as Node -> 0
	parent[0] = -1; // start node has no parent
	value[0] = 0; // start node has value = 0 to get picked 1st
	
	//from MST with (v-1) edges
	for (int i = 0; i < nodes-1; i++)
	{
		//select best vertex applying greedy method
		int u = selectMinVertex (value, setMST);

		setMST[u] = true; //include new vertex in MST
		
		//relax adjacent vertices (noy yet included in MST)
		for (int j = 0; j < nodes; j++)
		{
			/* 3 constraints to relax :-
					1. edge is present from u to j
					2. vertex j is not included in MST
					3. edge weight is smaller than current edge weight
			*/
			
			if (graph[u][j] != 0 && setMST[j] == false && graph[u][j] < value[j])
			{
				value[j] = graph[u][j];
				parent[j] = u;
			}
		}
	}
	
	//print MST
	for (int i = 1; i < nodes; i++)
	{
		cout << "u -> v : " << parent[i] << "->" << i << ", weight = " << graph[parent[i]][i] << endl;
	}
	
}

int main ()
{
    ll nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;

    ll graph[nodes][nodes]; // Adjacency matrix to store the graph
    for (ll i = 0; i < nodes; i++) {
        for (ll j = 0; j < nodes; j++) {
            graph[i][j] = 0;
        }
    }
						
	findMST(graph);
	
	return 0;
}

//time complexity : O(V^2)
//if we use adjacency list : O(E log V)