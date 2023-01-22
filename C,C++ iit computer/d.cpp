#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s=0;
    int a[7];
    cin>>n;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<7;j++)
       {
           cin>>a[j];
           s=s+a[j];
       }
       cout<<s<<endl;
       s=0;
    }


    return 0;
}

