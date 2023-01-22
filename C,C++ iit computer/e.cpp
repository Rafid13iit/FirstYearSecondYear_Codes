#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int t, n, i;

    cin >> t;

    for (i=0; i<t; i++){
        int n;

        cin >> n;

        cout << (n-1)*n/2 << endl;
    }

    return 0;
}
