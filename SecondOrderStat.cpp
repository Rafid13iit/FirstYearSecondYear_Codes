#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n, temp;
    cin >> n;

    set <int> s;

    for (int i = 0; i < n; i++){
        cin >> temp;
        s.insert(temp);
    }

    auto it = s.begin();

    /*for (auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }*/

    if (s.size() == 1) {
        cout << "NO";
    }

    else {
        it++;
        cout << *it;
    }

    return 0;
}