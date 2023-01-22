#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,m; cin>>n;

    int mx2[n][n], mx1[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            mx2[i][j]=-1;
        mx1[i]=0;
    }
    cin>>m;
    getchar();

    for(int i=0;i<m;i++)
    {
        char a,b;
        int cost;
        cin>>a>>b>>cost;
        getchar();

        int c=(int)(a-'A');
        int d=(int)(b-'A');

        mx2[c][d]=cost;
        mx2[d][c]-cost;
    }
    char ds; cin>>ds;
    cout<<"Paths :"<<"A ";
    mx1[0]=1;


    for(int i=0;i<n;)
    {
        int low=10000,in;
        char ch;
        for(int j=0;j<n;j++)
        {
            if(mx2[i][j]!=-1){
                if(mx2[i][j]<low and mx1[j]!=1){

                    low=mx2[i][j];
                    ch=(char)('A'+j);
                    in=j;
                }

            }

        }
        cout<<ch<<" ";
        if(ch==ds) break;

        mx1[in]=1;
        i=in;

    }
    cout<<endl;
}