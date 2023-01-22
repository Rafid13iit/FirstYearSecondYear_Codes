#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef  unsigned long long int llu;

int main ()
{
    ll t, result = 1, base, power;
    cin >> t;

    while (t--){
        cin >> base >> power;

        while (power != 0){

            if (power % 2 == 1){
                result *= base;
                power -= 1;
            }
            else {
                base *= base;
                power /= 2;
            }
        }

        cout << result << endl;
        result = 1;
    }

    return 0;
}