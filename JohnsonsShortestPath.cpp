#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define INF INT_MAX

using namespace std;

// Returns the vertex with minimum distance from the source
int minDistance(vector<int>& dist, vector<bool>& visited) {
    int minimum = INF;
    int minVertex = 0;
    for (int vertex = 0; vertex < dist.size(); vertex++) {
        if (minimum > dist[vertex] && !visited[vertex]) {
            minimum = dist[vertex];
            minVertex = vertex;
        }
    }
    return minVertex;
}

// Dijkstra Algorithm for Modified Graph (removing negative weights)
void Dijkstra(vector<vector<int>>& graph, vector<vector<int>>& modifiedGraph, int src) {
    int numVertices = graph.size();
    vector<bool> sptSet(numVertices, false);
    vector<int> dist(numVertices, INF);
    dist[src] = 0;

    for (int count = 0; count < numVertices; count++) {
        int curVertex = minDistance(dist, sptSet);
        sptSet[curVertex] = true;

        for (int vertex = 0; vertex < numVertices; vertex++) {
            if (!sptSet[vertex] && dist[vertex] > dist[curVertex] + modifiedGraph[curVertex][vertex] && graph[curVertex][vertex] != 0) {
                dist[vertex] = dist[curVertex] + modifiedGraph[curVertex][vertex];
            }
        }
    }

    // Print the shortest distance from the source
    for (int vertex = 0; vertex < numVertices; vertex++) {
        cout << "Vertex " << vertex << ": " << dist[vertex] << endl;
    }
}

// Function to calculate shortest distances from source to all other vertices using Bellman-Ford algorithm
vector<int> BellmanFord(vector<vector<int>>& edges, int numVertices) {
    vector<int> dist(numVertices + 1, INF);
    dist[numVertices] = 0;

    for (int i = 0; i < numVertices; i++) {
        for (const auto& edge : edges) {
            int src = edge[0];
            int des = edge[1];
            int weight = edge[2];
            if (dist[src] != INF && dist[src] + weight < dist[des]) {
                dist[des] = dist[src] + weight;
            }
        }
    }

    return vector<int>(dist.begin(), dist.begin() + numVertices);
}

// Function to implement Johnson Algorithm
void JohnsonAlgorithm(vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<vector<int>> edges;

    // Create a list of edges for Bellman-Ford Algorithm
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({ i, j, graph[i][j] });
            }
        }
    }

    vector<int> modifyWeights = BellmanFord(edges, numVertices);

    vector<vector<int>> modifiedGraph(numVertices, vector<int>(numVertices, 0));

    // Modify the weights to get rid of negative weights
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] != 0) {
                modifiedGraph[i][j] = graph[i][j] + modifyWeights[i] - modifyWeights[j];
            }
        }
    }

    cout << "Modified Graph:" << endl;
    for (const auto& row : modifiedGraph) {
        for (int weight : row) {
            cout << weight << "\t";
        }
        cout << endl;
    }

    // Run Dijkstra for every vertex as source one by one
    for (int src = 0; src < numVertices; src++) {
        cout << "\nShortest Distance with vertex " << src << " as the source:" << endl;
        Dijkstra(graph, modifiedGraph, src);
    }
}

// Driver Code
int main() {
    vector<vector<int>> graph = {
        { 0, -5, 2, 3 },
        { 0, 0, 4, 0 },
        { 0, 0, 0, 1 },
        { 0, 0, 0, 0 }
    };

    JohnsonAlgorithm(graph);

    return 0;
}
