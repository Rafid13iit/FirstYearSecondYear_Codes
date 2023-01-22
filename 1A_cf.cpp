#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main ()
{
    long long int n, m, a;
    double x, y;

    cin >> n >> m >> a;

    x = (double)n / a;
    y = (double)m / a;

    //cout << ceil(x) << endl << ceil(y) << endl;

    n = ceil(x) * ceil(y);
    cout << n;

    return 0;
}