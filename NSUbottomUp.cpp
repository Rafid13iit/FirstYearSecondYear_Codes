#include <iostream>
#define MAX 100
using namespace std;
int F[MAX];

int NSU (int n)
{
    for (int i = 0; i <= n; i++){
        if (i <= 2){
            F[i] = i;
        }
        else {
            F[i] = F[i-1] + F[i-2] + F[i-3];
        }
    }

    return F[n];
}

//index :   0 1 2 3 4 5  6  7  8  9   10 ...
//          0 1 2 3 6 11 20 37 68 125 230 ...

int main ()
{
    int n;
    cout << "Give a position to find the nth member of a NSU series : ";
    cin >> n;

    cout << NSU(n) << endl;

    return 0;
}

