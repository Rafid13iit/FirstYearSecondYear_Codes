#include <bits/stdc++.h>
#include <cstdlib> //it's used for the srand(), rand() functions, which generates random numbers.
#include <ctime>

using namespace std;

int main() {
  int nodes, edges;
  cout << "Enter the number of nodes: ";
  cin >> nodes;
  cout << "Enter the number of edges: ";
  cin >> edges;

  int adj_matrix[nodes][nodes]; // Adjacency matrix to store the graph

  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      adj_matrix[i][j] = 0;
    }
  }

  srand(time(0));

  /* time(0) is a function from the ctime header file
   that returns the current calendar time as the number of seconds
    elapsed since the epoch (00:00:00 UTC, January 1, 1970).*/

  /* When used as an argument for srand, 
  time(0) serves as a seed for the random number generator rand()
  to ensure that a different set of random numbers is generated 
  every time the code is run.*/

  int u, v;
  int count = 0;

  while (count < edges) {
    u = rand() % nodes;
    v = rand() % nodes;

    if (u != v && adj_matrix[u][v] != 1) {
      adj_matrix[u][v] = 1;
      adj_matrix[v][u] = 1; // Comment this line for directed graph
      count++; //keeping track of the number of edges added to the graph.
    }
  }

  cout << "Constructed random graph:\n";
  for (int i = 0; i < nodes; i++) {
    cout << i << ": ";

    for (int j = 0; j < nodes; j++) {
      if (adj_matrix[i][j] == 1) {
        cout << j << " ";
      }
    }

    cout << endl;
  }

  return 0;
}
