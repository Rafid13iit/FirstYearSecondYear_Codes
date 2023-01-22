#include <iostream>
#define MAX 100
using namespace std;
int C[MAX][MAX];

int rec (int n, int r)
{
    if (C[n][r] >= 0) return C[n][r];

    if (r == 1) C[n][r] = n;
    else if (r == n || r == 0) C[n][r] = 1;
    else C[n][r] = rec(n-1, r-1) + rec(n-1, r);

    return C[n][r];
}

int Comb (int n, int r)
{
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= min(i, r); j++){
            C[i][j] = -1;
        }
    }

    return rec(n, r);
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
