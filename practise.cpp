
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

int main()
{
   ll n,q,x;
   scanf("%lld%lld",&n,&q);
   ll a[n],b[q];
   for(ll i=0;i<n;i++)
   scanf("%lld",&a[i]);
   for(ll i=0;i<q;i++)
    {

        scanf("%lld",&b[i]);
    }
   for(ll i=0;i<q;i++)
    {
        ll sum=0;

        for(ll j=0;j<n;j++)
        {
            //i=0;
            sum+=abs(a[j]-b[i]);
           // i++;
        }
        printf("%lld", sum);
    }
}
