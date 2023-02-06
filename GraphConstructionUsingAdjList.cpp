#include <iostream>
#include <vector>

using namespace std;

int main() {
  int nodes, edges;
  cout << "Enter the number of nodes: ";
  cin >> nodes;
  cout << "Enter the number of edges: ";
  cin >> edges;

  vector<vector<int>> adj_list(nodes); // Adjacency list to store the graph

  int u, v;
  cout << "Enter edges (u v):\n";
  for (int i = 0; i < edges; i++) {
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u); // Comment this line for directed graph
  }

  cout << "Constructed graph:\n";
  for (int i = 0; i < nodes; i++) {
    cout << i << ": ";
    for (int j = 0; j < adj_list[i].size(); j++) {
      cout << adj_list[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
