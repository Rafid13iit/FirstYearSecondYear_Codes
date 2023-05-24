#include <bits/stdc++.h>
using namespace std;

// A structure to represent an edge in the graph
struct Edge {
  int to, label;
};

// A structure to represent a vertex in the graph
struct Vertex {
  int label;
  vector<Edge> edges;
};

// Function to check if two vertices are isomorphic
bool isIsomorphic(Vertex u, Vertex v) {
  // Check if the two vertices have the same degree and label
  if (u.edges.size() != v.edges.size() || u.label != v.label) {
    return false;
  }

  // Check if the edges of the two vertices have the same labels
  for (int i = 0; i < u.edges.size(); i++) {
    if (u.edges[i].label != v.edges[i].label) {
      return false;
    }
  }

  return true;
}

// Function to check if two graphs are isomorphic
bool isGraphIsomorphic(vector<Vertex> graph1, vector<Vertex> graph2) {
  // Check if the two graphs have the same number of vertices
  if (graph1.size() != graph2.size()) {
    return false;
  }

  map<int, int> mapping;
  return isGraphIsomorphicUtil(graph1, graph2, mapping, 0);
}

// A helper function to perform depth-first search
bool isGraphIsomorphicUtil(vector<Vertex> graph1, vector<Vertex> graph2, map<int, int> &mapping, int vertex) {
  // If all vertices have been matched, return true
  if (vertex == graph1.size()) {
    return true;
  }

  // Try to match the current vertex with all vertices in the second graph
  for (int i = 0; i < graph2.size(); i++) {
    if (mapping.count(i) == 0 && isIsomorphic(graph1[vertex], graph2[i])) {
      mapping[i] = vertex;
      if (isGraphIsomorphicUtil(graph1, graph2, mapping, vertex + 1)) {
        return true;
      }
      mapping.erase(i);
    }
  }

  return false;
}

int main() {
  // Example usage of the function
  vector<Vertex> graph1 = {{1, {{2, 1}, {3, 2}}},
                           {2, {{1, 1}, {3, 3}}},
                           {3, {{1, 2}, {2, 3}}}};
  vector<Vertex> graph2 = {{2, {{1, 3}, {3, 2}}},
                           {3, {{1, 2}, {2, 1}}},
                           {1, {{2, 3}, {3, 1}}}};

  if (isGraphIsomorphic(graph1, graph2)) {
    cout << "The two graphs are isomorphic." << endl;
  } else {
    cout << "The two graphs are not isomorphic." << endl;
  }

  return 0;
}
