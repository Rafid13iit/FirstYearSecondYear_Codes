#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll n, count = 0;

    cin >> n;
    ll a[n];

    a[0] = -10000;

    for (ll i = 1; i <= n; i++){
        cin >> a[i];

        if (a[i] < a[i-1]) {
            count += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }

    cout << count;

    return 0;
}
