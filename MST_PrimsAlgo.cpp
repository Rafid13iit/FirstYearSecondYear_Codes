#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int graph[MAX][MAX];
int v, edges;

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

int findMST (int graph[MAX][MAX])
{
	int parent[v], sum = 0;
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

	for (int i = 1; i < v; i++)
	{
		sum += graph[parent[i]][i];
	}

	return sum;
	
}

int main ()
{
    cout << "Enter the number of nodes: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }

	int u1, u2, weight;

	cout << "Enter edges (u v) and it's weight:\n";
    for (int i = 0; i < edges; i++) 
	{
        cin >> u1 >> u2 >> weight;
        graph[u1][u2] = weight;
		graph[u2][u1] = weight;
    }

	cout << "MST cost is : " << findMST(graph) << endl;
	
	return 0;
}

//time complexity : O(V^2)
//if we use adjacency list : O(E log V)
/*
9
14
0 1 4
1 2 8
2 3 7 
3 4 9
4 5 10
5 6 2
6 7 1
7 8 7
0 7 8
1 7 11
2 8 2
6 8 6
2 5 4
3 5 14
*/