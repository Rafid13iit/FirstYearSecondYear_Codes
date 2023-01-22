#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll stopage, a, b, c, d, max = 0;
    cin >> stopage;

    vector <ll> v;

    cin >> a >> b;
    max = b;
    stopage--;
    while(stopage--){
        cin >> c >> d;

        if (b - c + d > max) max = b - c + d;

        b = b - c + d;
    }

    cout << max;

    return 0;
}
