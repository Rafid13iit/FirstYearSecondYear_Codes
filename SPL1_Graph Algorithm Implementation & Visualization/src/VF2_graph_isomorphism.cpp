#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define N 100

vector<int> g1[N], g2[N]; //adjacency lists to represent the two graphs.
int degree1[N], degree2[N]; //arrays to store the degrees of the vertices in the two graphs.
unordered_map<int, int> labels1, labels2; //unordered maps to store the labels of the vertices in the two graphs.
bool used1[N], used2[N]; //are arrays to keep track of whether a vertex has been used in the mapping or not.
int n, m; // number of vertices in each graph, number of edges in each graph

//is a helper function to check if two vertices from the two graphs are isomorphic.
bool check(int u1, int u2) {
    if (degree1[u1] != degree2[u2]) return false;
    if (labels1[u1] != labels2[u2]) return false;
    return true;
}

bool dfs(int u1, int u2) {
    used1[u1] = true;
    used2[u2] = true;
    if (!check(u1, u2)) return false;

    for (int i = 0; i < g1[u1].size(); i++) {
        int v1 = g1[u1][i];
        bool found = false;

        for (int j = 0; j < g2[u2].size(); j++) {
            int v2 = g2[u2][j];
            if (!used2[v2] && dfs(v1, v2)) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool isIsomorphic() {
    for (int i = 0; i < n; i++) {
        if (degree1[i] != degree2[i]) return false;
        labels1[i] = g1[i].size();
        labels2[i] = g2[i].size();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (degree1[i] == degree2[j] && !used1[i] && !used2[j]) {
                if (dfs(i, j)) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g1[u].push_back(v);
        degree1[u]++;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g2[u].push_back(v);
        degree2[u]++;
    }
    if (isIsomorphic()) cout << "The two graphs are isomorphic." << endl;
    else cout << "The two graphs are not isomorphic." << endl;
    return 0;
}

//Example 1
/*
6
6
1 2
1 4
2 3
3 6
4 5 
5 6
6
6
1 5
1 4
2 4
2 6
3 5
3 6

Isomorphic
*/

//Example 2
/*
6
6
1 2
1 4
2 3
3 6
4 5
5 6
6
6
1 3
1 5
2 4
2 6
3 5
4 6

NOT isomorphic
*/
