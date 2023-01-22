#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int gcd (ll a, ll b)
{
    if (b == 0){
        return a;
    }

    return gcd(b, a % b);
}

int main ()
{
    ll t, a, b;
    cin >> t;

    while (t--){
        cin >> a >> b;

        cout << gcd(a, b) << nl;
    }

    return 0;
}
