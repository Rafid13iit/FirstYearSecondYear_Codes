#include <iostream>
using namespace std;

int Comb (int n, int r)
{
    if (r == 1) return n;
    else if (r == n || r == 0) return 1;
    else return (Comb(n-1, r-1) + Comb(n-1, r));
}

int main ()
{
    int n, r;

    cout << "Input the value of n : ";
    cin >> n;
    cout << "Input the value of r : ";
    cin >> r;

    cout << "nCr is : " << Comb(n, r) << endl;

    return 0;
}
