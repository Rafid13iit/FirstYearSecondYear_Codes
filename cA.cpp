#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll t;
    string str1, str2;

    cin >> t;

    while (t--){
        cin >> str1;
        str2 = str1;

        reverse(str2.begin(), str2.end());

        str1 = str1 + str2;

        cout << str1 << nl;
    }

    return 0;
}
