#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll n, count = 0;
    cin >> n;

    for (ll i = 1; i <= 9; i++){
        for (ll j = 1; j <= 9; j++){
            if (i * j == n) {
                count++;
                break;
            }
        }
        if (count == 1) break;
    }

    if (count == 1) cout << "Yes";
    else cout << "No";


    return 0;
}
