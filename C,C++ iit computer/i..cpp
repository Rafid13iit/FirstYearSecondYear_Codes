#include<bits/stdc++.h>
using namespace std;
int main()
{
     long long int t,n,k=0,l=0,m=0,s=0;
  long long  int i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
       long long int p=k;
        //cout<<"k="<<k<<endl;
        int a[n];
        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        for(j=n-1;j>=0;j--)
        {
            //cout<<"mod"<<a[j]%2<<endl;
            if(a[j]%2==0)
            {
                l++;
               // cout<<"l="<<l<<endl;

                if(l<=p)
                {
                   //cout<<"k="<<k<<endl;
                    //cout<<"Nasir"<<endl;
                    s=s+a[j];
                }
            }
            else if(a[j]%2!=0)
            {
                m++;
                //cout<<"m="<<m<<endl;
                if(m<=p)
                {
                    s=s+a[j];
                }
            }
        }
        cout<<s<<endl;
        s=0;
        l=0;
        m=0;
    }

    return 0;
}

