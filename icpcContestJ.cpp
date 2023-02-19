#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;



int main() {
    ll t;
    cin >> t;
    for(ll i=1;i<=t;i++) {
        ll n,k;
        cin>>n>>k;
        ll a[n],sum=0;
        for(ll i=0;i<n;i++)
       {
        cin>>a[i];
        sum+=a[i];
       }
       ll m=*max_element(a,a+n);
       cout<<"Case "<<i<<": "<<sum+(k-1)*m<<endl;
        //ll g = gcd(a, gcd(b, c));
        /*if (g > k)
            cout << "Case " << i << ": Fight" << endl;
        else
            cout << "Case " << i << ": Peaceful" << endl; */
    }
    return 0;
}
/*

2 4 6 2
2 8 12 2
*/
