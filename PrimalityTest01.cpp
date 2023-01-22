#include <bits/stdc++.h>
using namespace std;

bool prime (int n)
{
    if (n < 2) return  false;
    else if (n <= 3) return true;
    else if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i+=2){
        if (n % i == 0) return false;
    }
    return true;
}

int main ()
{
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        if (prime(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}