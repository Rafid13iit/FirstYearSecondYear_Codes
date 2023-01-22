#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll n;
    cin >> n;
    cout << n << " ";

    while (n != 1){
        if (n % 2 == 0){
            n /= 2;
            cout << n << " ";
        }
        else {
            n = n * 3 + 1;
            cout << n << " ";
        }
    }

    return 0;
}
