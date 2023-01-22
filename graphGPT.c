#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct {
  int n;
  int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph* create_graph(int n) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->n = n;
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      graph->adj_matrix[i][j] = 0;
    }
  }
  return graph;
}

void add_edge(Graph* graph, int i, int j) {
  graph->adj_matrix[i][j] = 1;
  graph->adj_matrix[j][i] = 1;
}

void print_graph(Graph* graph) {
  int i, j;
  for (i = 0; i < graph->n; i++) {
    printf("%d: ", i);
    for (j = 0; j < graph->n; j++) {
      if (graph->adj_matrix[i][j] == 1) {
        printf("%d ", j);
      }
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = create_graph(5);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 4);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 1, 4);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);
  print_graph(graph);
  return 0;
}
