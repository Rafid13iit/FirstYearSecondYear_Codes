#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll n, m, k, count = 0;
    cin >> n >> m >> k;
    ll a[n], b[m];

    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }

    for (ll i = 0; i < m; i++){
        cin >> b[i];
    }

    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){

            if (a[i]-k <= b[j] && b[j] <= a[i]+k){
                count++;
                b[j] = -10;
                break;
            }
        }
    }

    cout << count;

    return 0;
}
