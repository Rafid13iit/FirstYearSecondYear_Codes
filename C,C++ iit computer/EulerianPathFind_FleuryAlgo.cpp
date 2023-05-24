#include <bits/stdc++.h>
using namespace std;


bool isConnected(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    
    // Perform BFS from any vertex
    queue<int> q;
    q.push(0);
    visited[0] = true;

    // Continue BFS until all vertices are visited
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u = 0; u < n; u++) {
            if (graph[v][u] == 1 && !visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    // Check if all vertices are visited
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return false;
    }

    return true;
}

// Function to find the starting vertex
int findStartVertex(vector<vector<int>>& graph) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        int deg = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1)
                deg++;
        }
        if (deg % 2 != 0)
            return i;
    }
    return 0;
}

// Depth-first search
int dfs(vector<vector<int>>& graph, int prev, int start, vector<bool>& visited) {
    int count = 1;
    visited[start] = true;
    int n = graph.size();
    for (int u = 0; u < n; u++) {
        if (prev != u && !visited[u] && graph[start][u] == 1) {
            count += dfs(graph, start, u, visited);
        }
    }
    return count;
}

// Check if an edge is a bridge
bool isBridge(vector<vector<int>>& graph, int u, int v) {
    int deg = 0;
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1)
            deg++;
    }
    if (deg > 1)
        return false;
    return true;
}

// Fleury's algorithm
void fleuryAlgorithm(vector<vector<int>>& graph, int start) {
    int edge = 0;
    int v_count = graph.size();
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1)
                edge++;
        }
    }
    vector<bool> visited(n, false);
    for (int v = 0; v < n; v++) {
        if (graph[start][v] == 1) {
            vector<bool> visited(n, false);
            if (isBridge(graph, start, v))
                v_count--;
            int cnt = dfs(graph, start, v, visited);
            if (cnt - v_count <= 2) {
                cout << "Edge: " << start << " -> " << v << endl;
                if (isBridge(graph, v, start))
                    v_count--;
                graph[start][v] = graph[v][start] = 0;
                edge--;
                fleuryAlgorithm(graph, v);
            }
        }
    }
}

int main() {
    int n; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    int m; // Number of edges
    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    int startVertex = findStartVertex(graph);

    if (isConnected(graph)){
        cout << "Euler Path:" << endl;
        fleuryAlgorithm(graph, startVertex);
    }
    else{
        cout << "Graph is not connected. Euler Path does not exist." << endl;
    }

    return 0;
}

/*
6
8
0 1
0 2
1 2
1 3
1 4
3 4
3 5
4 5

output:

Euler Path:
Edge: 3 -> 1
Edge: 1 -> 0
Edge: 0 -> 2
Edge: 2 -> 1
Edge: 1 -> 4
Edge: 4 -> 3
Edge: 3 -> 5
Edge: 5 -> 4
*/