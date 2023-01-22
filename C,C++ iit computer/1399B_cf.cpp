#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int t, n, i, j, min_a, min_b, cnt = 0;
    cin >> t;

    for (i=1; i<=t; i++){
        cin >> n;

        int a[n], b[n];

        for (j=0; j<n; j++){
            cin >> a[i];
        }

        for (j=0; j<n; j++){
            cin >> b[i];
        }

        min_a = *min_element(a, a+n);
        min_b = *min_element(b, b+n);

        for (j=0; j<n; j++){
            if (a[i] == min_a || b[i] == min_b){
                if (min_a > a[i])
            }
        }
    }

    return 0;
}
