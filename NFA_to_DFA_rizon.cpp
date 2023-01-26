#include<bits/stdc++.h>
using namespace std;
struct dfa
{
    string s1;
}up[8];

void NfatoDfa(string s)
{
    //cout<<s<<endl;

    string q="a",p1;
    up[0].s1="a";up[1].s1="ab";up[2].s1="abc";up[3].s1="abcd";

    //cout<<q;
    int k=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='0')
        {
           // p1=up[k].s1;
           if(k<=3){
            cout<<"("<<p1<<","<<s[i]<<")"<<"->"<<up[0].s1<<endl;
            //cout<<p1<<endl;
           }
           else
           {
                cout<<"("<<up[3].s1<<","<<s[i]<<")"<<"->"<<up[0].s1<<endl;
           }
        }
        else if(s[i]=='1')
        {
            k++;
           // cout<<up[k].s1<<endl;
           if(k<=3){
            //p1=up[k].s1;
            cout<<"("<<up[k-1].s1<<","<<s[i]<<")"<<"->"<<up[k].s1<<endl;
           }
           else
           {
                cout<<"("<<up[3].s1<<","<<s[i]<<")"<<"->"<<up[3].s1<<endl;
           }
        }p1=up[k].s1;


    }
}
int main()
{
    string s;
    cin>>s;
    int c=0,p=0,q=0,pt;
    char d='a';
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='0'&&c==0)

        {
            c=0;
            cout<<"("<<d<<","<<s[i]<<")"<<"->"<<d<<endl;
            continue;
        }
        else if(s[i]=='1')
        {
            c++;
            cout<<"("<<d<<","<<s[i]<<")";
            d++;
            cout<<"->"<<d<<endl;
            if(c==3)
            {
                p=1;q=1;
                break;
            }
        }
        else if(s[i]=='0'&&c!=0)
        {
            c=0;
            char ch='a';
            cout<<"("<<d<<","<<s[i]<<")"<<"->"<<ch<<endl;
            d='a';
            continue;
        }
    }
    if(p==1)
    {
       
        cout<<"The string is accepted"<<endl;
        NfatoDfa(s);
    }
    else
        cout<<"The string is not accepted"<<endl;
    //10101001011011100110101
    //10101010001100101
}
