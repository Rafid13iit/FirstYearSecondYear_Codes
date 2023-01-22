#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
typedef long long int ll;
typedef  unsigned long long int llu;

long long int fact(long long int n) {
   if (n == 0 || n == 1)
   return 1;
   else
   return n * fact(n - 1);
}

int main ()
{

    cout << fact(2) << endl;
    cout << fact(3) << endl;
    cout << fact(4) << endl;
    cout << fact(5) << endl;
    cout << fact(6) << endl;
    cout << fact(7) << endl;

    return 0;
}