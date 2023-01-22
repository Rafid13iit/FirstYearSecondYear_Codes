#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin >> n;

    map <string, int> m;

    for (int i = 0; i < n; i++){
        string str;
        cin >> str;

        if (m[str] == 0){
            cout << "OK" << endl;
        }

        else {
            cout << str << m[str] << endl;
        }

        m[str]++;

    }

    return 0;
}