#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;

int main ()
{
ll a, b;
cin >> a >> b;

if ((a <= 9 && a >= 1) && (b<= 9 && b >= 1)) cout << a*b;
else cout << -1;

return 0;
}
