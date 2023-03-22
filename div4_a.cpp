#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long int llu;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define all(x) x.begin(),x.end()

int main ()
{
    ll t, n, sum = 0;
    cin >> t;

    while(t--){
        cin >> n;
        string str;
        cin >> str;

        for (ll i = 0; i < str.length(); i++){
            for (ll j = i; j < str.length(); j++){
            
                if ((str[i] == str[j]) && (i % 2 == 0) && (j % 2 == 0)) continue;
                else if ((str[i] == str[j]) && (i % 2 != 0) && (j % 2 != 0)) continue;
                else if (str[i] != str[j]) continue;
                else sum++;
            }
        }

        if (sum == 0) cout << "YES" << endl;
        else cout << "NO" << endl;

        sum = 0;
    }

    return 0;
}