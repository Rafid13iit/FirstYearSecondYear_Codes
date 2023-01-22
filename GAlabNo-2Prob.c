#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 100
#define INFINITY 9999

int distance[MAX_CITIES][MAX_CITIES]; // distance[i][j] is the distance between city i and city j
int path[MAX_CITIES]; // path[i] is the city that comes before city i in the best path
int visited[MAX_CITIES]; // visited[i] is 1 if city i has been visited, 0 otherwise

int numCities; // number of cities
int startCity; // starting city
int endCity; // destination city

// Find the city with the minimum distance from the starting city that has not yet been visited
int findMin(int start) {
  int minCity = -1;
  int minDist = INFINITY;
  for (int i = 0; i < numCities; i++) {
    if (!visited[i] && distance[start][i] < minDist) {
      minCity = i;
      minDist = distance[start][i];
    }
  }
  return minCity;
}

// Find the best path from the starting city to the destination city using a greedy algorithm
void findPath(int start, int end) {
  visited[start] = 1;
  int current = start;
  while (current != end) {
    int next = findMin(current);
    path[next] = current;
    visited[next] = 1;
    current = next;
  }
}

int main() {
  // Read in the number of cities and the distances between them
  scanf("%d", &numCities);
  for (int i = 0; i < numCities; i++) {
    for (int j = 0; j < numCities; j++) {
      scanf("%d", &distance[i][j]);
    }
  }

  // Read in the starting city and the destination city
  scanf("%d %d", &startCity, &endCity);

  // Find the best path from the starting city to the destination city
  findPath(startCity, endCity);

  // Print the best path
  printf("Best path: ");
  int current = endCity;
  while (current != startCity) {
    printf("%d ", current);
    current = path[current];
  }
  printf("%d\n", startCity);

  return 0;
}
