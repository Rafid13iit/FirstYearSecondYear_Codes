#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef set<si> ssi;
#define pb push_back
#define all(x) x.begin(),x.end()
#define nl endl
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i > (b); --i)
#define trav(x, v) for (auto& x : v)

int main ()
{
    vi v;
    ll x;

    rep (i, 0, 10){
        x = i+1;
        v.pb(x);
    }

    // trav(x, v){
    //     cout << x << nl;
    // }


    return 0;
}