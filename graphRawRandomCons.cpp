#include <bits/stdc++.h>
#include <cstdlib> //it's used for the srand(), rand() functions, which generates random numbers.
#include <ctime>

using namespace std;

unsigned int seed = 0; // initialize seed value
unsigned int a = 1103515245; // multiplier
unsigned int c = 12345; // increment
unsigned int m = 0xffffffff; // modulus

unsigned int rand_num(unsigned int &seed) {
  seed = (a * seed + c) % m;
  return seed;
}

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
int count = 0;
while (count < edges) {
  u = rand_num(seed) % nodes;
  v = rand_num(seed) % nodes;
  if (u != v && adj_matrix[u][v] != 1) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1; // Comment this line for directed graph
    count++;
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
