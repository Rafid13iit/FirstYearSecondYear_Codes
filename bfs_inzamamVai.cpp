#include <bits/stdc++.h>
using namespace std;

#define max_size 6

int G[max_size][max_size];
char C[max_size];
int Lev[max_size];
int par[max_size];



int main()
{
    int edgeCount;
    cin >> edgeCount;

    for (int i = 0; i < edgeCount; ++i) {
        int u, v;
        cin >> u >> v;

        G[u][v] = 1;
    }

    int sourceNode;
    cin >> sourceNode;

    //step-1
    for (int i = 0; i < max_size; ++i) {
        C[i] = 'w';
        Lev[i] = 99999999;
        par[i] = -1;
    }

    //step-2
    int Queue[max_size];
    int startP, endP;
    startP = 0;
    endP = 0;
    Queue[endP] = sourceNode;
    endP = endP + 1;
    C[sourceNode] = 'g';
    Lev[sourceNode] = 0;
    par[sourceNode] = -1;


    while (endP - startP > 0) {
        int u = Queue[startP];
        for (int i = 0; i < max_size; ++i) {
            int v = i;

            if (G[u][v] == 1 && C[v] == 'w') {
                Queue[endP] = v;
                endP = endP + 1;
                C[v] = 'g';
                Lev[v] = Lev[u] + 1;
                par[v] = u;
            }
        }
        startP = startP + 1;
        C[u] = 'b';
    }

    for (int i = 0; i < max_size; ++i) {
        cout << "Level[" << i << "] = " << Lev[i] << "\n";
        cout << "Parent[" << i << "] = " << par[i] << "\n";
        cout << "Color[" << i << "] = " << C[i] << "\n";
        cout << "\n";
    }

    return 0;
}

/*
6
5 2
5 1
5 3
1 3
1 4
4 2
5
*/