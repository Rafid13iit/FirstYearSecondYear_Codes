#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long int n, i, ans = 0, temp;
    cin >> n;

    map <long long int, long long int> m;

    for (i = 0; i < n; i++){
        long long int num;
        cin >> num;

        m[num]++;
    }

    for (auto it = m.begin(); it != m.end(); it++){
        temp = it -> second;
        ans = max(ans, temp);
    }

    cout << ans;

    return 0;
}