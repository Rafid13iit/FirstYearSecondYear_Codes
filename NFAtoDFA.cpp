#include<bits/stdc++.h>
using namespace std;

#define pb              push_back
#define all(x)          x.begin(),x.end()
typedef vector<int>     vi;
typedef vector<vi>      vvi;


vi state;
vi fs; //final states
vector<vvi> trans; //transition table for NFA
int checkNFA(string s);
vi closure(int s, vector<vvi> v);
void print(vvi st, vector<vvi> dfaTable);


int main()
{
    state.resize(4);
    trans.resize(4);

    cout<<"States: (4 states, 1st one is the inital state)"<<endl;
    for(int i=0;i<4;i++) cin>>state[i];

    cout<<"Number of final states:"<<endl;
    int f; 
    cin>>f;
    for(int i=0;i<f;i++){
        int x;
        cin>>x;
        fs.pb(x);
    }

    cout<<"NFA transition table:"<<endl;
    for(int i=0;i<4;i++){
        trans[i].resize(3);

        cout<<"Number of states for input 0 in increasing order:"<<endl;
        int n; 
        cin>>n;
        for(int j=0;j<n;j++){
            int x; 
            cin>>x;
            trans[i][0].pb(x);
        }

        cout<<"Number of states for input 1 in increasing order:"<<endl;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            int x; 
            cin>>x;
            trans[i][1].pb(x);
        }
    }

    cout<<"String:"<<endl;
    string s; 
    cin>>s;
    if(checkNFA(s)) cout<<"Accepted"<<endl;
    else cout<<"Not Accepted "<<endl;
    
    vector<vvi> dfaTable;
    vvi st;
    st.pb(closure(0,trans));

    queue<vi> q;
    q.push(st[0]);
    while(!q.empty())
    {
        vi a=q.front(); 
        q.pop();

        vvi v;
        for(int i=0;i<2;i++)
        {
            vi t;
            set<int> s;
            for(int j=0;j<a.size();j++){

                for(int k=0;k<trans[a[j]][i].size();k++){
                    vi c=closure(trans[a[j]][i][k],trans);
                    for(int l=0;l<c.size();l++) s.insert(c[l]);
                }
            }

            for(auto x:s) t.pb(x);
            v.pb(t);
            if(find(all(st),t)==st.end()){
                st.pb(t);
                q.push(t);
            }
        }
        dfaTable.pb(v);
    }
    cout<< endl << "DFA Table:" << endl << endl;
    print(st,dfaTable);
}


int checkNFA(string s)
{
    int init=state[0],prev=init,Final;
    
    for(int i=0;i<s.size();i++)
    {
        if(prev==state[0])
        {
            if(s[i]=='0')
            {
                int x=trans[state[0]][0].size();
                if(x) Final=trans[state[0]][0][x-1];
                else Final=state[0];
                
            }
            else if(s[i]=='1')
            {
                int x=trans[state[0]][1].size();
                if(x) Final=trans[state[0]][1][x-1];
                else Final=state[0];
            }
        }
        else if(prev==state[1])
        {
            if(s[i]=='0')
            {
                int x=trans[state[1]][0].size();
                if(x) Final=trans[state[1]][0][x-1];
                else Final=state[0];
            }
            else if(s[i]=='1')
            {
                int x=trans[state[1]][1].size();
                if(x) Final=trans[state[1]][1][x-1];
                else Final=state[0];
            }
        }
        else if(prev==state[2])
        {
            if(s[i]=='0')
            {
                int x=trans[state[2]][0].size();
                if(x) Final=trans[state[2]][0][x-1];
                else Final=state[0];
            }
            else if(s[i]=='1')
            {
                int x=trans[state[2]][1].size();
                if(x) Final=trans[state[2]][1][x-1];
                else Final=state[0];
            }
        }
        else if(prev==state[3])
        {
            int x=trans[state[2]][1].size();
            if(x) Final=trans[state[2]][1][x-1];
            else Final=state[0];
        }
        prev=Final;
        cout<<"Current state: "<<Final<<endl;
    }
    
    for(auto x:fs)
    {
        if(Final==x) return 1;
    }
    return 0;
}

vi closure(int s,vector<vvi> v)
{
    vi t;
    t.pb(s);
    queue<int> q;
    int x=v[s][2].size(); 
    for(int i=0;i<x;i++)
    {
        t.pb(v[s][2][i]);
        q.push(t[i]);
    }
    while(!q.empty())
    {
        int a=q.front(); q.pop();
        if(!v[a][2].empty())
        {
            int u=v[a][2].size();
            for(int i=0;i<u;i++)
            {
                int y=v[a][2][i];
                if(find(all(t),y)==t.end())
                {
                    t.pb(y);
                    q.push(y);
                }
            }
        }
    }
    return t;
}

void print(vvi st,vector<vvi> dfaTable)
{
    cout<<"States" << "\t\t\t" << "0" << "\t\t\t" << "1" <<endl;
    cout << "----------------------------------------------------------" << endl;
    for(int i=0;i<st.size();i++)
    {
        for(int j=0;j<st[i].size();j++)
        {
            cout<<st[i][j]<<" ";
        }
        cout<<"\t\t\t";
        for(int j=0;j<dfaTable[i].size();j++)
        {
            if(j==0) cout<<"{ ";
            else cout<<"{ ";
            for(int k=0;k<dfaTable[i][j].size();k++)
            {
                cout<<dfaTable[i][j][k]<<" ";
            }
            cout<<"}\t\t\t";
        }
        cout<<endl;
    }
}


/*
 0 1 2 3
 1
 3
 1
 0
 2
 0 1
 0
 1
 2
 0
 1
 3
 1
 3
 1
 3
 110001001(not accepted)/0001100111(accepted)
 */


