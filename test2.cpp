#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

vector<pii> adj[105]; // adjacency list to represent graph

int dijkstra(int src, int dest) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(105, INF);
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == dest) {
            return dist[dest];
        }

        for (auto v : adj[u]) {
            int new_dist = max(dist[u], v.second); // use maximum of current distance and edge weight
            if (new_dist < dist[v.first]) {
                dist[v.first] = new_dist;
                pq.push({new_dist, v.first});
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

        if (C == 0 && S == 0 && Q==0) break;

        if (T > 1) {
            cout << "\n";
        }
        cout << "Case #" << T++ << "\n";

        for (int i = 1; i <= C; i++) {
            adj[i].clear();
        }

        // read edges and build adjacency list
        for (int i = 0; i < S; i++) {
            int c1, c2, d;
            cin >> c1 >> c2 >> d;
            adj[c1].push_back({c2, d});
            adj[c2].push_back({c1, d});
        }

        // process queries
        for (int i = 0; i < Q; i++) {
            int c1, c2;
            cin >> c1 >> c2;
            int dist = dijkstra(c1, c2);
            if (dist == -1) {
                cout << "no path\n";
            } else {
                cout << dist << "\n";
            }
        }
    }

    return 0;
}
