#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t, i;
    cin>>t;
    for (i=1; i<=t; i++)
    {
        int a[4];
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        sort(a,a+3);
        int d=a[3];
        if(((a[1]-a[0])==d)&&((a[2]-a[1])==d))
            cout<<"Case " << i << ": Peaceful"<<endl;
        else
             cout<<"Case " << i << ": Fight"<<endl;
    }
}
