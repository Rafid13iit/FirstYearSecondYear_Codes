#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b;
    string s;
    cin>>t;
    while(t--)
{
    cin>>a>>b;

if(a>=b)
{
   for(int i=0;i<a+b;i++)
        {s[i]='0';}

    for(int i=1;i<b*2;i=i+2)
        {
            s[i]='1';

        }
}
   if(a<b)
{
   for(int i=0;i<a+b;i++)
        {s[i]='1';}

        for(int i=1;i<a*2;i=i+2)
        {
            s[i]='0';

        }
}

for(int i=0;i<a+b;i++)
{
    cout<<s[i];
}

cout<<endl;
s.clear();
}

}



