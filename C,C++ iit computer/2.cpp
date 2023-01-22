#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int t, n, a, b, c, k, i;
    cin >> t;

    for (i=1; i<=t; i++){
        cin >> a >> b >> c >> k;

        if (a == b && b == c) cout << "Case " << i << ": Peaceful" << endl;

        else if ((a+b+c)%3 != 0) cout << "Case " << i << ": Fight" << endl;

        else {
            int x = (a+b+c) / 3;

            if (abs(x-a)%k == 0 && abs(x-b)%k == 0 && abs(x-c)%k == 0)
                cout << "Case " << i << ": Peaceful" << endl;
            else
                cout << "Case " << i << ": Fight" << endl;
        }
    }

    return 0;
}
