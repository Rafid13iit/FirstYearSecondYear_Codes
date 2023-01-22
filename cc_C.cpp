#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll t, n, count = 0, result = 0;
    cin >> t;
    while (t--){
        cin >> n;
        ll a[n], b[n];

        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++){
            cin >> b[i];
        } 

        for (ll i = 0; i < n; i++){
            if (a[i] != 0 && b[i] != 0) count++;
            else count = 0;
            if (result <= count) result = count;
        }

        cout << result << endl;
        result = count = 0; 
    }

    return 0;
}
