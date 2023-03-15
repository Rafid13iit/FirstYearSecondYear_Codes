#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 1e9;

int adj[MAXN][MAXN]; // adjacency matrix to represent graph

int dijkstra(int src, int dest, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, INF);
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == dest) {
            return dist[dest];
        }

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != -1) {
                int new_dist = max(dist[u], adj[u][v]); // use maximum of current distance and edge weight
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    pq.push({new_dist, v});
                }
            }
        }
    }

    return -1; // no path found
}

int main() {

    freopen ("dijk.txt", "r", stdin);

    int T = 1; // test case number
    int C = 1, S = 1, Q = 1;

    while (1) {
        cin >> C >> S >> Q;

        if (C == 0 && S == 0 && Q==0) break; // terminates when 0 0 0

        if (T > 1) {
            cout << endl;
        }
        cout << "Case #" << T++ << endl;

        memset(adj, -1, sizeof(adj)); // initialize adjacency matrix to -1

        // read edges and build adjacency matrix
        for (int i = 0; i < S; i++) {
            int c1, c2, d;
            cin >> c1 >> c2 >> d;
            adj[c1][c2] = d;
            adj[c2][c1] = d;
        }

        // input the queries
        for (int i = 0; i < Q; i++) {
            int c1, c2;
            cin >> c1 >> c2;
            int dist = dijkstra(c1, c2, C);
            if (dist == -1) {
                cout << "no path" << endl;
            } else {
                cout << dist << endl;
            }
        }
    }

    return 0;
}
