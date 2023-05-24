#include <bits/stdc++.h>
using namespace std;

void tarjanDFS(int u, vector<vector<int>>& graph, vector<int>& discoveryTime, vector<int>& lowLink, vector<bool>& onStack, stack<int>& nodeStack, vector<vector<int>>& SCCs, int& time) {
    discoveryTime[u] = lowLink[u] = ++time;
    nodeStack.push(u);
    onStack[u] = true;

    for (int v : graph[u]) {
        if (discoveryTime[v] == -1) {
            tarjanDFS(v, graph, discoveryTime, lowLink, onStack, nodeStack, SCCs, time);
            lowLink[u] = min(lowLink[u], lowLink[v]);
        } 
        
        else if (onStack[v]) {
            lowLink[u] = min(lowLink[u], discoveryTime[v]);
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

vector<vector<int>> tarjanSCC(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<int> discoveryTime(n, -1);
    /*the discovery time of each vertex during the Tarjan's algorithm. */

    vector<int> lowLink(n, -1);
    /*the Lowg-link value of a node is the smallest/lowest
    node id reachable from that node when doing a DFS (including itself)*/

    vector<bool> onStack(n, false);
    /*keeps track of whether a vertex is currently on the stack 
    during the Tarjan's algorithm*/

    stack<int> nodeStack;
    /*stores the vertices during the depth-first search traversal.*/

    vector<vector<int>> SCCs;
    /*vector of vectors that will store the strongly connected components found.*/

    int time = 0;
    /* keeps track of the discovery time during the algorithm.*/

    for (int i = 0; i < n; ++i) {
        if (discoveryTime[i] == -1) {
            tarjanDFS(i, graph, discoveryTime, lowLink, onStack, nodeStack, SCCs, time);
        }
    }

    return SCCs;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
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