#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll t, following, followers;
    cin >> t;

    while (t--){
        cin >> following >> followers;

        if (((double)following / (double)followers)  > 10) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}
