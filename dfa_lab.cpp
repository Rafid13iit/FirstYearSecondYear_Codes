#include<bits/stdc++.h>
using namespace std;

void NfatoDfa(string s); //prototype

int main()
{
    string str;
    cin>>str;
    int c=0,p=0;
    char d='a';

    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='0'&&c==0)

        {
            c=0;
            cout<<"("<<str[i]<<","<<d<<")"<<"->"<<d<<endl;
            continue;
        }
        else if(str[i]=='1')
        {
            c++;
            cout<<"("<<str[i]<<","<<d<<")";
            d++;
            cout<<"->"<<d<<endl;
            if(c==3)
            {
                p=1;
                break;
            }
        }
        else if(str[i]=='0'&&c!=0)
        {
            c=0;
            d='a';
            cout<<"("<<str[i]<<","<<d<<")"<<"->"<<d<<endl;
            continue;
        }
    }
    if(p==1)
    {
        cout<<"The string is accepted"<<endl;
        NfatoDfa(str);
    }
    else
        cout<<"The string is not accepted"<<endl;
    //10101001011011100110101
    //10101010001100101
}
void NfatoDfa(string str)
{
    //cout<<s<<endl;

    string q="a",p1;
    //up[0].s1="a";up[1].s1="ab";up[2].s1="abc";up[3].s1="abcd";
    char c='a';
    //cout<<q;
    int k=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='0')
        {
           // p1=up[k].s1;
           if(k<=3){
            cout<<"("<<q<<","<<str[i]<<")"<<"->"<<"a"<<endl;
            //cout<<p1<<endl;
           }
           else
           {
                cout<<"("<<q<<","<<str[i]<<")"<<"->"<<"a"<<endl;
           }
        }
        else if(str[i]=='1')
        {
            k++;
           // cout<<up[k].s1<<endl;
           if(k<=3){
            //p1=up[k].s1;
            c++;
            string p=q;
            q=q+c;
            cout<<"("<<p<<","<<str[i]<<")"<<"->"<<q<<endl;
           }
           else
           {
                cout<<"("<<q<<","<<str[i]<<")"<<"->"<<q<<endl;
           }
        }
        //p1=up[k].s1;
    }
}

