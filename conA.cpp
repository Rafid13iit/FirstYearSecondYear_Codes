#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int t, a, b, c;
    cin >> t;

    while (t--){
        cin >> a >> b >> c;

        set <int> s;

        s.insert(a);
        s.insert(b);
        s.insert(c);

        auto it = s.begin();

        *it++;

        cout << *it << endl;
    }
    return 0;
}