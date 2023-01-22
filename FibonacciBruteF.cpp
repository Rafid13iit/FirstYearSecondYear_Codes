#include <iostream>
using namespace std;

int Fibo (int n)
{
    if (n <= 1){
        return n;
    }
    else {
        return (Fibo (n-1) + Fibo (n-2));
    }
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

