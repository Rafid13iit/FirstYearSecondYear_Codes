#include <bits/stdc++.h>
using namespace std;

void primeFact(int n)
{
    set <int> s;

    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            
            int count = 0;
            while(n % i == 0){
                count++;
                n = n / i;
                s.insert(i);
            }

        }
    }

    if (n > 1) cout << s.size() + 1 << endl;
    else cout << s.size() << endl;
}

int main ()
{

    while (1){
        int n;
        cin >> n;

        if (n == 0) break;

        primeFact (n);
    }

    return 0;
}