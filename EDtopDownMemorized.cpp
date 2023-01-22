//using bottom up method

#include <bits/stdc++.h>
#define MAX 100
using namespace std;

string str1, str2;
int num = 1;

void PrintED(int i, int j, int Remember[][MAX], int Arrow[][MAX]) {
    if(i == 0 && j == 0) return;

    if(Arrow[i][j] == 0) {
        PrintED(i, j-1, Remember, Arrow);
        cout << num << ". insert '" << str2[j-1] << "'" << endl;
        num++;
    }
    else if(Arrow[i][j] == 1) {
        PrintED(i-1, j, Remember, Arrow);
        cout << num << ". delete '" << str1[i-1] << "'" << endl;
        num++;
    }
    else {
        PrintED(i-1, j-1, Remember, Arrow);
        if(str1[i-1] != str2[j-1]) {
            cout << num << ". replace '" << str1[i-1] << "' with '" << str2[j-1] << "'" << endl;
            num++;
        }
    }
}



//0 is rigth arrow
//1 is down arrow
//2 is cross arrow

int ED(int i, int j, int Remember[][MAX], int Arrow[][MAX])
{
    for (i = 0; i <= str1.length(); i++){
        for (j = 0; j <= str2.length(); j++){

            if (i == 0 && j == 0) {
                Remember[i][j] = 0;
                Arrow[i][j] = 0;
            }
            else if (i == 0) {
                Remember[i][j] = Remember[i][j-1] + 1;
                Arrow[i][j] = 0;
            }
            else if (j == 0) {
                Remember[i][j] = Remember[i-1][j] + 1;
                Arrow[i][j] = 1;
            }
            else{
                if (str1[i-1] == str2[j-1]) {
                    Remember[i][j] = Remember[i-1][j-1];
                    Arrow[i][j] = 2;
                }
                else {
                    Remember[i][j] = 1 + min(Remember[i][j-1], min(Remember[i-1][j], Remember[i-1][j-1]));

                    if (Remember[i][j]-1 == Remember[i][j-1]) Arrow[i][j] = 0;
                    else if (Remember[i][j]-1 == Remember[i-1][j-1]) Arrow[i][j] = 2;
                    else Arrow[i][j] = 1;
                }
            }
        }
    }

    return Remember[str1.length()][str2.length()];
}

int main ()
{
    freopen("text_ED.txt", "r", stdin);
    
    int i = 0, j = 0;

    cout << "Enter string 1 : ";
    cin >> str1;
    cout << "Enter string 2 : ";
    cin >> str2;

    int Remember[MAX][MAX], Arrow[MAX][MAX];
    memset(Remember, -1, sizeof(Remember));

    cout << "To convert \"" << str1 << "\" to \"" << str2 << "\" the ED is : " << ED(i, j, Remember, Arrow) << endl;
    cout << "The steps are given below :" << endl;
    PrintED(str1.length(), str2.length(), Remember, Arrow);

    return 0;
}