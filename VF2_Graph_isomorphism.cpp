#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int g1[MAX][MAX];
int g2[MAX][MAX];

bool isIsomorphic() {
    int n1, m1;
    cin >> n1 >> m1;

    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        g1[u][v] = g1[v][u] = 1;
    }

    int n2, m2;
    cin >> n2 >> m2;

    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        g2[u][v] = g2[v][u] = 1;
    }

    if (n1 != n2)
        return false;

    unordered_map<int, int> degreeCount1, degreeCount2;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            degreeCount1[i] += g1[i][j];
            degreeCount2[i] += g2[i][j];
        }
    }

    if (degreeCount1 != degreeCount2)
        return false;

    unordered_map<int, unordered_map<int, int>> labelCount1, labelCount2;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            if (g1[i][j]) {
                labelCount1[i][degreeCount1[j]]++;
            }
            if (g2[i][j]) {
                labelCount2[i][degreeCount2[j]]++;
            }
        }
    }

    return labelCount1 == labelCount2;
}

int main() {
    if (isIsomorphic())
        cout << "The two graphs are Isomorphic." << endl;
    else
        cout << "The two graphs are Not isomorphic." << endl;

    return 0;
}



//Example 1
/*
8
12
0 1
0 3
0 4
1 2
1 5 
2 3
2 6
3 7
4 5
4 7
5 6
6 7
8
12
0 1
0 3
0 5
2 1
2 3
2 7
4 1
4 5
4 7
6 3
6 5
6 7

Isomorphic
*/

//Example 2
/*
6
6
0 1
0 3
1 2
2 5
3 4 
4 5
6
6
0 4
0 3
1 3
1 5
2 4
2 5

Isomorphic
*/

//Example 3
/*
6
6
0 1
0 2
1 2
2 5
3 4
4 5
6
6
0 2
0 4
1 3
1 5
2 4
3 5

NOT isomorphic
*/
