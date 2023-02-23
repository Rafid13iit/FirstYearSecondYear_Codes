#include<bits/stdc++.h>
using namespace std;

#define pb              push_back
#define all(x)          x.begin(),x.end()
typedef vector<int>     vi;
typedef vector<vi>      vvi;


vi state;
vi fs; //final states
vector<vvi> trans; //transition table for NFA
int checkDFA(string s, vector<vvi> dfaTable, vvi st);
vi closure(int s,vector<vvi> v);
void print(vvi st,vector<vvi> dfaTable);


int main()
{
    state.resize(4); trans.resize(4);
    cout<<"States: (4 states, 1st one is the inital state)"<<endl;
    for(int i=0;i<4;i++) cin>>state[i];
    cout<<"Number of final states:"<<endl;
    int f; cin>>f;
    for(int i=0;i<f;i++)
    {
        int x; cin>>x;
        fs.pb(x);
    }
    cout<<"NFA transition table:"<<endl;
    for(int i=0;i<3;i++)
    {
        trans[i].resize(3);
        cout<<"Number of states for input 0 in increasing order:"<<endl;
        int n; cin>>n;
        for(int j=0;j<n;j++)
        {
            int x; cin>>x;
            trans[i][0].pb(x);
        }
        cout<<"Number of states for input 1 in increasing order:"<<endl;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            int x; cin>>x;
            trans[i][1].pb(x);
        }
        cout<<"Number of epsilon transitions:"<<endl;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            int x; cin>>x;
            trans[i][2].pb(x);
        }
    }
    cout<<"String:"<<endl;
    string s; cin>>s;
    // convert E-NFA to DFA using subset construction
    vector<vvi> dfaTable;
    vvi st;
    st.pb(closure(0,trans));
    queue<vi> q;
    q.push(st[0]);
    while(!q.empty())
    {
        vi a=q.front(); q.pop();
        vvi v;
        for(int i=0;i<2;i++)
        {
            vi t;
            set<int> s;
            for(int j=0;j<a.size();j++)
            {
                for(int k=0;k<trans[a[j]][i].size();k++)
                {
                    vi c=closure(trans[a[j]][i][k],trans);
                    for(int l=0;l<c.size();l++) s.insert(c[l]);
                }
            }
            for(auto x:s) t.pb(x);
            v.pb(t);
            if(find(all(st),t)==st.end())
            {
                st.pb(t);
                q.push(t);
            }
        }
        dfaTable.pb(v);
    }
    cout<<"DFA Table:"<<endl;
    print(st,dfaTable);
    if(checkDFA(s, dfaTable, st)) cout<<"Accepted"<<endl;
    else cout<<"Not Accepted "<<endl;
}


int checkDFA(string s, vector<vvi> dfaTable, vvi st)
{
    int init=0,prev=init,Final;
    for(int i=0;i<s.size();i++)
    {
        if(prev==0)
        {
            if(s[i]=='0') Final=dfaTable[0][0][0];
            else Final=dfaTable[0][1][0];
        }
        else
        {
            int curr;
            if(s[i]=='0') curr=dfaTable[prev][0][0];
            else curr=dfaTable[prev][1][0];
            for(int j=1;j<dfaTable[prev][0].size();j++)
            {
                if(s[i]=='0' && dfaTable[prev][0][j]!=curr)
                {
                    curr=-1;
                    break;
                }
                if(s[i]=='1' && dfaTable[prev][1][j]!=curr)
                {
                    curr=-1;
                    break;
                }
            }
            Final=curr;
        }
        if(Final==-1) return 0;
        prev=Final;
    }
    if(find(all(fs),Final)!=fs.end()) return 1;
    else return 0;
}

vi closure(int s,vector<vvi> v)
{
    vi c; c.pb(s);
    queue<int> q; q.push(s);
    while(!q.empty())
    {
        int a=q.front(); q.pop();
        for(int i=0;i<v[a][2].size();i++)
        {
            if(find(all(c),v[a][2][i])==c.end())
            {
                c.pb(v[a][2][i]);
                q.push(v[a][2][i]);
            }
        }
    }
    return c;
}

void print(vvi st,vector<vvi> dfaTable)
{
    cout<<"States:\t\t"<<"0\t\t1"<<endl;
    for(int i=0;i<st.size();i++)
    {
        cout<<"{";
        for(int j=0;j<st[i].size();j++) cout<<st[i][j]<<",";
        cout<<"}\t\t{";
        for(int j=0;j<dfaTable[i][0].size();j++) cout<<dfaTable[i][0][j]<<",";
        cout<<"}\t\t{";
        for(int j=0;j<dfaTable[i][1].size();j++) cout<<dfaTable[i][1][j]<<",";
        cout<<"}\n";
    }
}


/*
0 1 2 3
1
3
1
1
2
2 3
1
3
0011
*/
