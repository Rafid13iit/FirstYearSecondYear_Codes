#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        ll a[3], k;
        cin >> a[0] >> a[1] >> a[2] >> k;

        sort(a, a+3);

        ll diff1 = fabs(a[0] - a[1]);
        ll diff2 = fabs(a[1] - a[2]);
        //ll x = diff / 3;

        if (a[0] == 0 && a[1] == 0 && a[2] == 0)
            cout << "Case " << i << ": Fight" << endl;
        else if ((a[0] == 0 && a[1] == 0 && a[2] != 0) || (a[0]+a[1]+a[2])%3 != 0)
            cout << "Case " << i << ": Fight" << endl;
        else if (diff1 == 0 && diff2 == 0)
            cout << "Case " << i << ": Peaceful" << endl;
        else if ((diff1 == 0 && diff2 != 0 && diff2 % k == 0) || (diff2 == 0 && diff1 != 0 && diff1 % k == 0))
            cout << "Case " << i << ": Peaceful" << endl;
        else if (((diff2 / diff1 == 3) || (diff2 / diff1 == 1)) && (diff1 % k == 0) && (diff2 % k == 0) )
            cout << "Case " << i << ": Peaceful" << endl;
        else
            cout << "Case " << i << ": Fight" << endl;
    }
    return 0;
}

/*

2 4 6 2
2 8 12 2
4 4 16 2

*/
