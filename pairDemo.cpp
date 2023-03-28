#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nStudents;

    cout << "How many students are there?" << endl;
    cin >> nStudents;
    
    pair <int, string> p[nStudents];

    cout << "Enter Name and numbers:" << endl;
    for (int i = 0; i < nStudents; i++)
    {
        cin >> p[i].second;
        cin >> p[i].first;
    }

    sort(p, p + nStudents);
    reverse(p, p + nStudents);

    cout << endl << "New list: " << endl;
    for (int i = 0; i < nStudents; i++)
    {
         cout << p[i].second << " " << p[i].first << endl;
    }
        
    return 0;
}