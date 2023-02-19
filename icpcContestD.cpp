#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ul unsigned long long int
#define endl "\n"


int main() {

      ios::sync_with_stdio(false);
      cin.tie(nullptr);


      ll t;
      cin>>t;

      for(ll k=1;k<=t;k++)
      {
          ll a,b,c,d;

          cin>>a>>b>>c>>d;
           bool flag = 0;

           ll sum = a+b+c;

           if( (sum%3)!=0 ) flag =1;
           else{
                ll modd = sum/3;

                 ll p, q, r;
                 p = abs(a-modd);
                 q= abs(b- modd);
                 r= abs(c - modd);

                 if( ((p%d)!=0) || ((q%d)!=0) || ((r%d)!=0)  )
                    {flag = 1;}

           }

           if(flag)
           {
            cout<<"Case "<<k<<": "<<"Fight"<<endl;
           }else
           {
            cout<<"Case "<<k<<": "<<"Peaceful"<<endl;
           }
      }

      return 0;

}