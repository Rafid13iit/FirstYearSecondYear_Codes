#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {

    freopen ("dijk2.txt", "r", stdin);

    int n = 0, m = 0;
    int a, b;

    for (int t = 1; ; t++) {
        int graph[105][105];
        memset(graph, INF, sizeof(graph));
        int cnt = 0, sum = 0;

        while (true) {
            cin >> a >> b;
            if (a == 0 && b == 0) break;
            graph[a][b] = 1;
            cnt++;
        }

        if (cnt == 0) break;

        n = 0;
        for (int k = 1; k <= 100; k++) {
            for (int i = 1; i <= 100; i++) {
                for (int j = 1; j <= 100; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 100; j++) {
                if (i != j && graph[i][j] != INF) {
                    sum += graph[i][j];
                    n++;
                }
            }
        }

        cout << "Case" << t << ": average length between pages = " << sum * 1.0 / n << " clicks" << endl;
    }

    return 0;
}