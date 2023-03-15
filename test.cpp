#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
const int INF = 1e9;

int adj[MAX][MAX];
int n, m; // number of nodes and edges

struct Edge {
    int u, v, w;
};

int mstPrim(int src) {
    bool visited[MAX] = {false};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int sum = 0;

    visited[src] = true;
    for (int i = 0; i < n; i++) {
        if (adj[src][i] != INF) {
            pq.push(make_pair(adj[src][i], i));
        }
    }

    while (!pq.empty()) {
        pair<int, int> t = pq.top();
        pq.pop();

        int u = t.second;
        int w = t.first;

        if (visited[u]) {
            continue;
        }

        visited[u] = true;
        sum += w;

        for (int i = 0; i < n; i++) {
            if (adj[u][i] != INF && !visited[i]) {
                pq.push(make_pair(adj[u][i], i));
            }
        }
    }

    return sum;
}

int main() {
    memset(adj, INF, sizeof(adj));

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        adj[e.u][e.v] = adj[e.v][e.u] = e.w;
    }

    cout << mstPrim(0) << endl;

    return 0;
}
