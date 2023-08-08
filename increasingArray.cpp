#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll n, count = 0;

    cin >> n;
    ll a[n+1], tmp[n];

    a[0] = -10000;

    for (ll i = 1; i <= n; i++){
        cin >> a[i];

        if (a[i] < a[i-1]) {
            tmp[i-1] = a[i] - a[i-1];
        }
        else{
            tmp[i-1] = 0;
        }
    }

    cout << count;

    return 0;
}
