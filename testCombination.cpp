#include <iostream>
using namespace std;

int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
   
    else
        return n * fact(n - 1);
}

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int main ()
{
    int n = 7;
    int r = 2;

    cout << nCr(n, r) << endl;

    return 0;
}
