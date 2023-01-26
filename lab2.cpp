#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

vi state; //total states
vi finalState; //final states
vector<vvi> trans_tableNFA; //transition table for NFA

int checkNFAorNOT(string s);
vi closureTEST(int s,vector<vvi> v);
void printDFA(vvi status,vector<vvi> DFAtable);



int main()
{
    state.resize(4); trans_tableNFA.resize(4);

    cout<<"Input the states: (4 states, 1st one is the inital state)"<<endl;
    for(int i=0;i<4;i++) cin>>state[i];

    cout<<"Number of final states:"<<endl;
    int f; cin>>f;
    for(int i=0;i<f;i++)
    {
        int x; cin>>x;
        finalState.pb(x);
    }

    //Taking input for NFA transition table
    cout<<"Input the transition table for NFA:"<< endl << endl;
    for(int i=0;i<4;i++)
    {
        trans_tableNFA[i].resize(3);
        cout<<"Number of transitions for alphabet 0 : ";
        int n;
        cin>>n;

        cout << "From " << i << " state to ";
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            trans_tableNFA[i][0].pb(x);
        }

        cout<<"Number of transitions for alphabet 1 : ";
        cin>>n;

        cout << "From " << i << " state to ";
        for(int j=0;j<n;j++)
        {
            int x; cin>>x;
            trans_tableNFA[i][1].pb(x);
        }
    }

    cout<< endl <<"String to test NFA:"<<endl;
    string str; cin>>str;
    cout << endl << endl;

    if(checkNFAorNOT(str)) cout<<"NFA Accepted"<<endl;
    else cout<<"NFA Not Accepted "<<endl;
    

    //NFA to DFA

    vector<vvi> DFAtable;
    vvi status;
    status.pb(closureTEST(0,trans_tableNFA));

    queue<vi> que;
    que.push(status[0]);

    while(!que.empty())
    {
        vi a=que.front(); que.pop();
        vvi v;

        for(int i=0;i<2;i++)
        {
            vi t;
            set<int> s;
            for(int j=0;j<a.size();j++)
            {
                for(int k=0;k<trans_tableNFA[a[j]][i].size();k++)
                {
                    vi c=closureTEST(trans_tableNFA[a[j]][i][k],trans_tableNFA);
                    for(int l=0;l<c.size();l++) s.insert(c[l]);
                }
            }

            for(auto x:s) t.pb(x);

            v.pb(t);
            if(find(all(status),t)==status.end())
            {
                status.pb(t);
                que.push(t);
            }
        }

        DFAtable.pb(v);
    }

    cout << endl << endl;
    cout<<"The transition table for DFA Table:"<<endl << endl;
    printDFA(status, DFAtable);
}


int checkNFAorNOT(string s)
{
    int init=state[0],prev=init,Final;
    
    for(int i=0;i<s.size();i++)
    {
        if(prev==state[0])
        {
            if(s[i]=='0')
            {
                int x=trans_tableNFA[state[0]][0].size();
                if(x) Final=trans_tableNFA[state[0]][0][x-1];
                else Final=state[0];
                
            }
            else if(s[i]=='1')
            {
                int x=trans_tableNFA[state[0]][1].size();
                if(x) Final=trans_tableNFA[state[0]][1][x-1];
                else Final=state[0];
            }
        }

        else if(prev==state[1])
        {
            if(s[i]=='0')
            {
                int x=trans_tableNFA[state[1]][0].size();
                if(x) Final=trans_tableNFA[state[1]][0][x-1];
                else Final=state[0];
            }
            else if(s[i]=='1')
            {
                int x=trans_tableNFA[state[1]][1].size();
                if(x) Final=trans_tableNFA[state[1]][1][x-1];
                else Final=state[0];
            }
        }

        else if(prev==state[2])
        {
            if(s[i]=='0')
            {
                int x=trans_tableNFA[state[2]][0].size();
                if(x) Final=trans_tableNFA[state[2]][0][x-1];
                else Final=state[0];
            }
            else if(s[i]=='1')
            {
                int x=trans_tableNFA[state[2]][1].size();
                if(x) Final=trans_tableNFA[state[2]][1][x-1];
                else Final=state[0];
            }
        }

        else if(prev==state[3])
        {
            int x=trans_tableNFA[state[2]][1].size();
            if(x) Final=trans_tableNFA[state[2]][1][x-1];
            else Final=state[0];
        }

        prev=Final;
        cout<<"Current state: "<<Final<<endl;
    }
    
    for(auto x:finalState)
    {
        if(Final==x) return 1;
    }

    return 0;
}

vi closureTEST(int s,vector<vvi> v)
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

void printDFA(vvi st,vector<vvi> dfaTable)
{
    cout<<"States"<<endl;

    for(int i=0;i<st.size();i++)
    {
        for(int j=0;j<st[i].size();j++)
        {
            cout<<st[i][j]<<" ";
        }
        cout<<"\t\t";

        for(int j=0;j<dfaTable[i].size();j++)
        {
            if(j==0) cout<<"for input 0: { ";
            else cout<<"for input 1: { ";
            for(int k=0;k<dfaTable[i][j].size();k++)
            {
                cout<<dfaTable[i][j][k]<<" ";
            }
            cout<<"}\t\t";
        }
        cout<<endl;
    }
}


//sample input

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


