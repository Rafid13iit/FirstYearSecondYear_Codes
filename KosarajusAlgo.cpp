#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Step 1: Perform DFS and store finishing order
void dfs(int node, vector<int>* graph, vector<bool>& visited, stack<int>& order) {
    visited[node] = true;

    // Visit all neighbors of the current node
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, order);
        }
    }

    // Push the current node to the stack when all neighbors are visited
    order.push(node);
}

// Step 2: Transpose the graph by reversing all edges
void transposeGraph(vector<int>* graph, vector<int>* transposedGraph, int n) {
    for (int node = 0; node < n; node++) {
        for (int neighbor : graph[node]) {
            transposedGraph[neighbor].push_back(node);
        }
    }
}

// DFS to identify the nodes in a strongly connected component (SCC)
void dfsSCC(int node, vector<int>* graph, vector<bool>& visited, vector<int>& scc) {
    visited[node] = true;
    scc.push_back(node);

    // Visit all neighbors of the current node
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsSCC(neighbor, graph, visited, scc);
        }
    }
}

// Find all SCCs in the graph
vector<vector<int>> findSCCs(vector<int>* graph, vector<int>* transposedGraph, int n) {
    vector<bool> visited(n, false);
    stack<int> order;
    vector<vector<int>> SCCs;

    // Step 1: Perform DFS on the original graph and store the finishing order
    for (int node = 0; node < n; node++) {
        if (!visited[node]) {
            dfs(node, graph, visited, order);
        }
    }

    // Step 2: Perform DFS on the transposed graph using the finishing order
    visited.assign(n, false); // Reset the visited array

    while (!order.empty()) {
        int node = order.top();
        order.pop();

        if (!visited[node]) {
            vector<int> scc;
            dfsSCC(node, transposedGraph, visited, scc);
            SCCs.push_back(scc);
        }
    }

    return SCCs;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int>* graph = new vector<int>[n];
    vector<int>* transposedGraph = new vector<int>[n];

    // Build the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    // Step 2: Transpose the graph
    transposeGraph(graph, transposedGraph, n);

    // Step 3: Find all SCCs
    vector<vector<int>> SCCs = findSCCs(graph, transposedGraph, n);

    // Output the SCCs
    for (const auto& scc : SCCs) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }

    // Clean up memory
    delete[] graph;
    delete[] transposedGraph;

    return 0;
}

/*
Example - 01:

8
14
0 1
7 0
1 7
1 6
7 6
1 2
6 5 
5 6
2 5
2 3
3 2
3 4
5 4
4 4

Output:
4 
5 6 
3 2 
7 1 0

*/