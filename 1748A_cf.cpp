#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long int t, n, i, j, sum = 0;
    cin >> t;
    
    for (i = 0; i < t; i++){
        cin >> n;
        
        /*for (j = 0; j < ceil(n / 2); j++){
            sum += 2 * (j + 1);
        }*/
        
        if (n % 2 == 0) cout << n / 2 << endl;
        else cout << n / 2 + 1 << endl;
    }
    
    return 0;
}