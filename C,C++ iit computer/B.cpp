#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, j, c = 0;

    cin >> t;

    for (i=0; i<t; i++){
        cin >> n;
        int a[n];

        cin >> a[0];
        for (j=1; j<n; j++){
            cin >> a[j];

            if (a[j] <= a[j-1]) c++;
        }

        if (c > 0) cout << "No" << endl;
        else cout << "Yes" << endl;

        c = 0;
    }

    return 0;
}
