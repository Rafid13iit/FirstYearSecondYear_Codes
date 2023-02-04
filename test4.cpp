#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll n;
    cin >> n;

    string s[16];

    s[0] = "1";

    // cout << s[1] << endl;

    for (ll i = 1; i <= 15; i++){
        s[i] = s[i-1] + " " + to_string(i+1) + " " + s[i-1];
    }

    // for (ll i = 1; i <= 16; i++){
    //     cout << s[i] << endl; 
    // }

    cout << s[n-1];

    return 0;
}
