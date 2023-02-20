#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef set<si> ssi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
#define nl endl
#define trav(i, a, b) for (int i = (a); i < (b); ++i)
#define rtrav(i, a, b) for (int i = (a); i > (b); --i)
#define pb push_back
#define eb emplace_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define rofn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rfor1(i, n) for (int i = (n); i >= 1; --i)
#define each(a, x) for (auto& a : x)
#define allin(a, x) for (auto a : x)
#define make_unique(x) sort(all(x)), x.resize(unique(all(x))-x.begin())



int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}



int main ()
{


    return 0;
}