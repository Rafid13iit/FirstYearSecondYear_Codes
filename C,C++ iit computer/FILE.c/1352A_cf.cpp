#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int t, i, j, count = 0;
    cin >> t;
    getchar();

    for (i=1; i<=t; i++){
        string a;
        getline (cin, a);

        for (j=1; j<a.length(); j++){
            if (a[j] != '0') count++;
        }

        cout << count + 1 << endl;
        count = 0;

        for (j=a.length()-1; j>0; j--){
            if (a[j] != '0') cout << a[j] << " ";
            a[j] = '0';
        }
        cout << a << endl;
    }

    return 0;
}
