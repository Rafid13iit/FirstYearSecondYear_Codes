//using Recursion method

#include <bits/stdc++.h>
using namespace std;

string str1, str2;

void PrintLCS(int i, int j, string LCSstr, int LCSlen) {
    if (str1[i] == '\0' || str2[j] == '\0') {

        if (LCSstr.length() == LCSlen) {
            cout << LCSstr << endl;
        }
        return ;
    }

    if (str1[i] == str2[j]) {
        PrintLCS(i+1, j+1, LCSstr+str1[i], LCSlen);
    } else {
        PrintLCS(i+1, j, LCSstr, LCSlen);
        PrintLCS(i, j+1, LCSstr, LCSlen);
    }
}


int LCS(int i, int j)
{
    if (str1[i] == '\0' || str2[j] == '\0'){
        return 0;
    }

    else if (str1[i] == str2[j]){
        return 1 + LCS(i+1, j+1);
    }

    else {
        return max(LCS(i+1, j), LCS(i, j+1));
    }
}

int main ()
{
    //freopen("text_LCS.txt", "r", stdin);
    
    int i = 0, j = 0;

    cout << "Enter string 1 : ";
    cin >> str1;
    cout << "Enter string 2 : ";
    cin >> str2;

    int LCSlen = LCS(i, j);

    cout << "Longest Common Subsequence length : " << LCSlen << endl;
    cout << "LCS is : ";
    PrintLCS(i, j, "", LCSlen);

    return 0;
}