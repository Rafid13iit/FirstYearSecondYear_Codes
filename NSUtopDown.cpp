#include <iostream>
#define MAX 100
using namespace std;
int F[MAX], n;

int NSU_rec (int n)
{
    if (F[n] >= 0){
        return F[n];
    }
    
    if (n <= 2){
        F[n] = n;
    }
    else {
        F[n] = NSU_rec(n-1) + NSU_rec(n-2) + NSU_rec(n-3);
    }

    return F[n];
}

int NSU (int n)
{
    for (int i = 0; i <= n; i++){
        F[i] = -1;
    }

    return NSU_rec(n);
}

//index :   0 1 2 3 4 5  6  7  8  9   10 ...
//          0 1 2 3 6 11 20 37 68 125 230 ...

int main ()
{
    int n;
    cout << "Give a position to find the nth member of a Fibonacci series : ";
    cin >> n;

    cout << NSU(n) << endl;

    return 0;
}

