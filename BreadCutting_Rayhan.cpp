#include<bits/stdc++.h>
using namespace std;

int const MAX = 1005;
int l, n;
int a[MAX];
int track[MAX][MAX]; //the array track is used to keep track of the minimum cost of cutting the bread.

int dp(int start, int finish){
    if(track[start][finish] != -1) return track[start][finish];

    bool f=false;
    int ans = INT_MAX;

    
    for(int i=1; i<=n; i++){
        if(a[i] <= start or a[i] >= finish) continue;

        f=true;

        ans = min(ans, finish - start + dp(start, a[i]) + dp(a[i], finish));
    }
    /*
    The purpose of this loop is to find the optimal cut position 
    between 'start' and 'finish' and update the minimum cost accordingly. 
    The cost of cutting the bread between 'start' and 'finish' is the sum
    of the cost of cutting the bread between 'start' and the current 
    cut position plus the cost of cutting the bread between the current cut position 
    and 'finish' and the value of 'finish' minus 'start'.
    It's using the dynamic programming method where it checks the subproblems 
    of the main problem and store the result of these subproblems 
    to use it in the main problem solution.
    */

    if(!f) track[start][finish] = 0;
    else track[start][finish] = ans;
    return track[start][finish];
}

int main(){
    int l; 
    cin >> l;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    memset(track, -1, sizeof track);

    cout << "Minimum cutting cost is: " << dp(0, l) << endl;

    return 0;
}
