#include <bits/stdc++.h>
using namespace std;

string polyalphabetic_encrypt(string plaintext, string key) {
    string ciphertext = "";

    for (int i = 0; i < plaintext.size(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[i % key.size()];

        if (plainChar == ' ') {
            ciphertext += ' ';
            continue;
        }

        keyChar = toupper(keyChar) - 'A';

        bool isUpper = isupper(plainChar);


        char cipherChar = (toupper(plainChar) - 'A' + keyChar) % 26 + 'A';

        if (!isUpper) {
            cipherChar = tolower(cipherChar);
        }

        ciphertext += cipherChar;
    }

    return ciphertext;
}

string polyalphabetic_decrypt(string ciphertext, string key) {
    string plaintext = "";

    for (int i = 0; i < ciphertext.size(); i++) {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % key.size()];

        if (cipherChar == ' ') {
            plaintext += ' ';
            continue;
        }

        keyChar = toupper(keyChar) - 'A';

        bool isUpper = isupper(cipherChar);



        if (!isUpper) {
            plainChar = tolower(plainChar);
        }

        plaintext += plainChar;
    }

    return plaintext;
}

int main() {
    string plaintext, key;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter key: ";
    cin >> key;

    string encrypted = polyalphabetic_encrypt(plaintext, key);
    string decrypted = polyalphabetic_decrypt(encrypted, key);

    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
