#include <bits/stdc++.h>
#define MAX 100
using namespace std;

string str1, str2;
int num = 1;
int Remember[MAX][MAX], Arrow[MAX][MAX];

void PrintED(int i, int j) {
    if(i == 0 && j == 0) return;

    if(Arrow[i][j] == 0) {
        PrintED(i, j-1);
        cout << num << ". insert '" << str2[j-1] << "'" << endl;
        num++;
    }
    else if(Arrow[i][j] == 1) {
        PrintED(i-1, j);
        cout << num << ". delete '" << str1[i-1] << "'" << endl;
        num++;
    }
    else {
        PrintED(i-1, j-1);
        if(str1[i-1] != str2[j-1]) {
            cout << num << ". replace '" << str1[i-1] << "' with '" << str2[j-1] << "'" << endl;
            num++;
        }
    }
}

int ED(int i, int j) {
    if (Remember[i][j] != -1) {
        return Remember[i][j];
    }

    if (i == 0 && j == 0) {
        Remember[i][j] = 0;
        Arrow[i][j] = -1;
    }
    else if (i == 0) {
        Remember[i][j] = ED(i, j-1) + 1;
        Arrow[i][j] = 0;
    }
    else if (j == 0) {
        Remember[i][j] = ED(i-1, j) + 1;
        Arrow[i][j] = 1;
    }
    else{
        if (str1[i-1] == str2[j-1]) {
            Remember[i][j] = ED(i-1, j-1);
            Arrow[i][j] = 2;
        }
        else {
            Remember[i][j] = 1 + min(ED(i, j-1), min(ED(i-1, j), ED(i-1, j-1)));

            if (Remember[i][j]-1 == ED(i, j-1)) Arrow[i][j] = 0;
            else if (Remember[i][j]-1 == ED(i-1, j-1)) Arrow[i][j] = 2;
            else Arrow[i][j] = 1;
        }
    }

    return Remember[i][j];
}

int main () {
    freopen("text_ED.txt", "r", stdin);

    int i = 0, j = 0;

    cout << "Enter string 1 : ";
    cin >> str1;
    cout << "Enter string 2 : ";
    cin >> str2;

    memset(Remember, -1, sizeof(Remember));

    cout << "To convert \"" << str1 << "\" to \"" << str2 << "\" the ED is : " << ED(str1.length(), str2.length()) << endl;
    cout << "The steps are given below :" << endl;
    PrintED(str1.length(), str2.length());

    return 0;
}
