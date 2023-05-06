#include <bits/stdc++.h>
using namespace std;
int main ()
{
    double course[6], GPA;

    cout << "Enter 6 course's GPA: " << endl;

    for (int i = 0; i  < 6; i++){
        cin >> course[i];
        GPA += course[i];
    }

    cout << endl << "Semester GPA : " << setprecision(3) << GPA / 6 << endl << endl;

    return 0;
}