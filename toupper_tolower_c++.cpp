#include <bits/stdc++.h>
using namespace std;
int main ()
{
    string str1 = "ASSALAMUALAIKUM!";
    string str2 = "walaikumussalam!";

    cout << "Before toupper and tolower :" << endl;
    cout << str1 << endl << str2 << endl;

    transform (str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform (str2.begin(), str2.end(), str2.begin(), ::toupper);

    cout << "After toupper and tolower :" << endl;
    cout << str1 << endl << str2 << endl;

    return 0;
}