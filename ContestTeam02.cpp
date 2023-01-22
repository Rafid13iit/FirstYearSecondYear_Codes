#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{

    ll t; cin>>t;
    for(ll i=1;i<=t;i++)
    {  
        cout << "Case " << i << ":" << endl;
        string s, d = "#"; cin>>s;
        ll q; cin>>q;
        
        vector<ll>v;
        while(q--)
        { 
            ll cnt =0;
            ll a,b; cin>>a>>b;
            char c=s[b];
            if (a == 1){
                for(ll j=0; j <= s.size(); j++){
                    if (s[j] == c){
                        cnt++;
                    }
                    else if(cnt != 0){
                        v.push_back(cnt);
                        cnt = 0;
                    }
                }

                cout << *max_element(v.begin(), v.end()) << endl;
            }

            else if(a==2){
                s[b]='#';
                cout<<s[b]<<endl;
            
            }







        }
    }
    return 0;
}
