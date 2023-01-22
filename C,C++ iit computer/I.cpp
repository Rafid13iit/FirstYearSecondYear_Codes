#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k, i, j, codd = 0, ceven = 0, sum = 0;

    cin >> t;

    for (i=0; i<t; i++){
        cin >> n >> k;
        int a[n];

        for (j=0; j<n; j++){
            cin >> a[j];

            sum += a[j];

            if (a[j] % 2 == 0) {
                ceven++;
                codd = 0;
            }
            else {
                codd++;
                ceven = 0;
            }

            if (ceven > k){
                sort(a[j+1-ceven], a[j+1-ceven] + ceven);
                sum -= a[j+1-ceven];
            }
            else if (codd > k){
                sort(a[j+1-codd], a[j+1-codd] + codd);
                sum -= a[j+1-codd];
            }
        }

        cout << sum << endl;

        sum = 0;
        ceven = 0;
        codd = 0;
    }

    return 0;
}

