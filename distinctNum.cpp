#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    set <ll> s;
    ll n, x;
    cin >> n;

    for (ll i = 0; i < n; i++){
        cin >> x;
        s.insert(x);
    }

    cout << s.size();
    
    return 0;
}
