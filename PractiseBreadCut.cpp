#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int bread_length, num_cuts;
int cut_positions[MAX];
int dp[MAX][MAX];

int cuttingCost(int start, int finish) {
    for (int len = 2; len <= num_cuts; len++) {
        for (int i = 0; i <= num_cuts - len; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + finish - start);
            }
        }
    }
    return dp[0][num_cuts];
}


int main() {
    cin >> bread_length >> num_cuts;

    for(int i = 1; i <= num_cuts; i++) cin >> cut_positions[i];

    memset(dp, -1, sizeof(dp));

    cout << "Minimum cutting cost is: " << cuttingCost(0, bread_length) << endl;
    
    return 0;
}
