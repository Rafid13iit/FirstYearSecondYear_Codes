#include <iostream>
#define MAX 100
using namespace std;
int F[MAX];

int Fibo (int n)
{
    for (int i = 0; i <= n; i++){
        if (i <= 1){
            F[i] = i;
        }
        else {
            F[i] = F[i-1] + F[i-2];
        }
    }

    return F[n];
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

