#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll t;
    cin >> t;
    ll a[3];
    while (t--){
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);

        if (a[2] == a[0]+a[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
