#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef unsigned long long int llu;

int main ()
{
    ll t, n;
    cin >> t;
    while (t--){
        cin >> n;

        if (n <= 9) cout << n << endl;
        else {
            cout << 9 + n / 10 << endl;
        }
    }
    return 0;
}
