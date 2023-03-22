#include <bits/stdc++.h>
using namespace std;

#define v 6

int selectMinVertex (vector<int>& value, vector<bool>& setMST)
{
	int minimum = INT_MAX;
	int vertex;
	
	for (int i = 0; i < v; i++)
	{
		if (setMST[i] == false && value[i] < minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	
	return vertex;
}

void findMST (int graph[v][v])
{
	int parent[v];
	vector<int> value (v, INT_MAX); //used edged relaxation
	vector<bool> setMST (v, false); //TRUE -> vertex is included in MST
	
	//Assuming start point as Node -> 0
	parent[0] = -1; // start node has no parent
	value[0] = 0; // start node has value = 0 to get picked 1st
	
	//from MST with (v-1) edges
	for (int i = 0; i < v-1; i++)
	{
		//select best vertex applying greedy method
		int u = selectMinVertex (value, setMST);
        
		setMST[u] = true; //include new vertex in MST
		
		//relax adjacent vertices (noy yet included in MST)
		for (int j = 0; j < v; j++)
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
	for (int i = 1; i < v; i++)
	{
		cout << "u -> v : " << parent[i] << "->" << i << ", weight = " << graph[parent[i]][i] << endl;
	}
	
}

int main ()
{
	int graph[v][v] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };
						
	findMST(graph);
	
	return 0;
}

//time complexity : O(V^2)
//if we use adjacency list : O(E log V)