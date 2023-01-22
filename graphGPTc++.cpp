#include <iostream>
#include <vector>

using namespace std;

const int MAX_VERTICES = 50;

class Graph {
 public:
  Graph(int n) : n_(n) {
    adj_list_.resize(n_);
  }

  void add_edge(int i, int j) {
    adj_list_[i].push_back(j);
    adj_list_[j].push_back(i);
  }

  void print_graph() {
    for (int i = 0; i < n_; i++) {
      cout << i << ": ";
      for (int j : adj_list_[i]) {
        cout << j << " ";
      }
      cout << endl;
    }
  }

 private:
  int n_;
  vector<vector<int>> adj_list_;
};

int main() {
  Graph graph(5);
  graph.add_edge(0, 1);
  graph.add_edge(0, 4);
  graph.add_edge(1, 2);
  graph.add_edge(1, 3);
  graph.add_edge(1, 4);
  graph.add_edge(2, 3);
  graph.add_edge(3, 4);
  graph.print_graph();
  return 0;
}
