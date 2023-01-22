#include <bits/stdc++.h>
using namespace std;

const int NUM = 31;

int main ()
{
    int t, n, x = 0;
    cin >> t;

    while (t--){
        cin >> n;
        char s[n];

        for (int i = 0; i < n; i++){
            cin >> s[i];

            if ((s[i] & NUM) >= x) x = s[i] & NUM;
        }

        cout << x << endl;
        x = 0;
    }
    return 0;
}