#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef  unsigned long long int llu;
#define mod 10

int main ()
{
    ll result = 1, base = 1378, power;

    cin >> power;

    while (power != 0){

        if (power % 2 == 1){
            result = (result * base) % mod;
            power -= 1; // power--
        }
        else {
            base = (base * base) % mod;
            power /= 2;
        }
    }

    cout << result << endl;
    result = 1;

    return 0;
}