#include <bits/stdc++.h>
using namespace std;
int main ()
{
    double t, i, a, b, c, sum = 0;
    cin >> t;

    for (i=1; i<=t; i++){
        cin >> a >> b >> c;

        double x = (a + b + c) / 3;
        sum = (a-x) + (b-x) + (c-x);

        if (sum == 0) cout << "Case " << i << ": Peaceful" << endl;
        else cout << "Case " << i << ": Fight" << endl;

        sum = 0;
        x = 0;
    }

    return 0;
}
