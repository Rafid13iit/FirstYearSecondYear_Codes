#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAX_SIZE = 100;

void tarjanDFS(int u, int graph[MAX_SIZE][MAX_SIZE], int discoveryTime[], int lowLink[], bool onStack[], stack<int>& nodeStack, vector<vector<int>>& SCCs, int& time) {
    discoveryTime[u] = lowLink[u] = ++time;
    nodeStack.push(u);
    onStack[u] = true;

    for (int v = 0; v < MAX_SIZE; v++) {
        if (graph[u][v] != 0) {
            if (discoveryTime[v] == -1) {
                tarjanDFS(v, graph, discoveryTime, lowLink, onStack, nodeStack, SCCs, time);
                lowLink[u] = min(lowLink[u], lowLink[v]);
            } else if (onStack[v]) {
                lowLink[u] = min(lowLink[u], discoveryTime[v]);
            }
        }
    }

    if (discoveryTime[u] == lowLink[u]) {
        vector<int> scc;
        while (true) {
            int v = nodeStack.top();
            nodeStack.pop();
            onStack[v] = false;
            scc.push_back(v);

            if (v == u) {
                break;
            }
        }

        SCCs.push_back(scc);
    }
}

vector<vector<int>> tarjanSCC(int graph[MAX_SIZE][MAX_SIZE]) {
    int discoveryTime[MAX_SIZE];
    int lowLink[MAX_SIZE];
    bool onStack[MAX_SIZE];
    stack<int> nodeStack;
    vector<vector<int>> SCCs;
    int time = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        discoveryTime[i] = -1;
        lowLink[i] = -1;
        onStack[i] = false;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        if (discoveryTime[i] == -1) {
            tarjanDFS(i, graph, discoveryTime, lowLink, onStack, nodeStack, SCCs, time);
        }
    }

    return SCCs;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    int graph[MAX_SIZE][MAX_SIZE] = {0};

    cout << "Enter the edges:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }

    vector<vector<int>> SCCs = tarjanSCC(graph);

    cout << "Strongly Connected Components:" << endl;
    for (const auto& scc : SCCs) {
        for (int vertex : scc) {
            cout << vertex << " ";
        }
        cout << endl;
    }

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