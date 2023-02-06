#include <iostream>

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

  int u, v;
  cout << "Enter edges (u v):\n";
  for (int i = 0; i < edges; i++) {
    cin >> u >> v;
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1; // Comment this line for directed graph
  }

  cout << "Constructed graph:\n";
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
