#include <bits/stdc++.h>
using namespace std;

vector <string> knownWords = {"abaculi", "abacus", "abacuses", "abide", "abduct", "abbreviation"};

int LCS(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int dp[m+1][n+1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

string correctWord(string misspelled) {
    int maxLCS = 0;
    string correct = "";

    for(auto word : knownWords) {
        int lcs = LCS(misspelled, word);
        if(lcs > maxLCS) {
            maxLCS = lcs;
            correct = word;
        }
    }

    return correct;
}

int main() {
    string misspelled;
    cout << "Enter the misspelled word: ";
    cin >> misspelled;

    string correct = correctWord(misspelled);
    cout << "The correct word is: " << correct << endl;
    return 0;
}
