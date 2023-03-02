//using top down recursion method method

#include <bits/stdc++.h>
#define MAX 100
using namespace std;

string str1, str2;

void PrintLCS(int i, int j, int Remember[][MAX]) {
    if (i == 0 || j == 0) {
        return;
    }

    if (str1[i-1] == str2[j-1]) {
        PrintLCS(i-1, j-1, Remember);
        cout << str1[i-1];
    } else if (Remember[i][j] == Remember[i-1][j]) {
        PrintLCS(i-1, j, Remember);
    } else {
        PrintLCS(i, j-1, Remember);
    }
}


int LCS(int i, int j, int Remember[][MAX])
{
    if (Remember[i][j] >= 0){
        return Remember[i][j];
    }

    if (str1[i] == '\0' || str2[j] == '\0'){
        Remember[i][j] = 0;
        return Remember[i][j];
    }
    else if (str1[i] == str2[j]){
        Remember[i][j] = 1 + LCS(i+1, j+1, Remember);
        return Remember[i][j];
    }
    else {
        Remember[i][j] = max(LCS(i+1, j, Remember), LCS(i, j+1, Remember));
        return Remember[i][j];
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

    int Remember[MAX][MAX];
    memset(Remember, -1, sizeof(Remember));

    cout << "Longest Common Subsequence length : " << LCS(i, j, Remember) << endl;
    cout << "LCS is : ";
    PrintLCS(str1.length(), str2.length(), Remember);

    return 0;
}