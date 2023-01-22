#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll n, i, x = 0, y = 0;
    cin >> n;

    for (i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            x = n / i;
            y = i;

        }
    }

    cout << y-1 + x-1;

    return 0;
}
