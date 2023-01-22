#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
     ll t, j, cnt = 0; cin>>t;
     for (j = 1; j <= t; j++){
    ll n; cin>>n;
    ll a[n], b[n];

    for (int i = 0 ; i < n; i++){
        cin >> a[i];
        if (a[i] % 2 == 0) b[i] = 1;
        else b[i] = 0;
    }

    cout << "Case " << j << ": "; 
    for (int i = 0 ; i < n; i++){
        if (b[i] == 0 && cnt == 0) {
            continue;
        }
        cnt++;
        cout << b[i];
    }
    cout << endl;
    cnt = 0;


}
return 0;
}