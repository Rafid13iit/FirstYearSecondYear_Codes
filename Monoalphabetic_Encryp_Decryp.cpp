#include <bits/stdc++.h>
using namespace std;

char monocipher_encr(char a);
char monocipher_decr(char a);

char alpha[86][2] = {
    // Lowercase letters
    {'a', 'f'}, {'b', 'a'}, {'c', 'g'}, {'d', 'u'}, {'e', 'n'}, {'f', 'i'}, {'g', 'j'},
    {'h', 'k'}, {'i', 'l'}, {'j', 'm'}, {'k', 'o'}, {'l', 'p'}, {'m', 'q'}, {'n', 'r'},
    {'o', 's'}, {'p', 't'}, {'q', 'v'}, {'r', 'w'}, {'s', 'x'}, {'t', 'y'}, {'u', 'z'},
    {'v', 'b'}, {'w', 'c'}, {'x', 'd'}, {'y', 'e'}, {'z', 'h'},
    
    // Uppercase letters
    {'A', 'F'}, {'B', 'A'}, {'C', 'G'}, {'D', 'U'}, {'E', 'N'}, {'F', 'I'}, {'G', 'J'},
    {'H', 'K'}, {'I', 'L'}, {'J', 'M'}, {'K', 'O'}, {'L', 'P'}, {'M', 'Q'}, {'N', 'R'},
    {'O', 'S'}, {'P', 'T'}, {'Q', 'V'}, {'R', 'W'}, {'S', 'X'}, {'T', 'Y'}, {'U', 'Z'},
    
    // Digits
    {'0', '9'}, {'1', '8'}, {'2', '7'}, {'3', '6'}, {'4', '5'}, {'5', '4'}, {'6', '3'},
    {'7', '2'}, {'8', '1'}, {'9', '0'},
    
    // Symbols
    {'+', '-'}, {'-', '+'}, {'@', '!'}, {'!', '@'}, {'#', '$'}, {'%', '&'}, {'*', '/'},
    {'$', '#'}, {'&', '%'}, {'/', '*'}//more symbols can be added
};


int main() {
    string str1, str2, str3;
    
    cout << "Enter String: ";
    // cin >> str1;
    getline(cin, str1);

    for (int i = 0; i < str1.size(); i++) {
        str2 += monocipher_encr(str1[i]);
    }
    cout << "After Encryption: " << str2 << endl;

    for (int i = 0; i < str2.size(); i++) {
        str3 += monocipher_decr(str2[i]);
    }
    cout << "After Decryption: " << str3 << endl;

    return 0;
}

//Encryption funtion
char monocipher_encr(char a) {
    for (int i = 0; i < 86; i++) {
        if (a == alpha[i][0])
            return alpha[i][1];
    }
    return a;
}

//Decryption function
char monocipher_decr(char a) {
    for (int i = 0; i < 86; i++) {
        if (a == alpha[i][1])
            return alpha[i][0];
    }
    return a;
}
