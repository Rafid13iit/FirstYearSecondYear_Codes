#include <iostream>
#define MAX 100
using namespace std;
int F[MAX], n;

int Fibo_rec (int n)
{
    if (F[n] >= 0){
        return F[n];
    }
    
    if (n <= 1){
        F[n] = n;
    }
    else {
        F[n] = Fibo_rec(n-1) + Fibo_rec(n-2);
    }

    return F[n];
}

int Fibo (int n)
{
    for (int i = 0; i <= n; i++){
        F[i] = -1;
    }

    return Fibo_rec(n);
}

//index :   0 1 2 3 4 5 6 7  8  9  10 ...
//          0 1 1 2 3 5 8 13 21 34 55 ...

int main ()
{
    int n;
    cout << "Give a position to find the nth member of a Fibonacci series : ";
    cin >> n;

    cout << Fibo(n) << endl;

    return 0;
}

