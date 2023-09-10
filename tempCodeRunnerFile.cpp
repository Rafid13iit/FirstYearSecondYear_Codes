#include <iostream>
#include <string>
using namespace std;

string polyalphabetic_encrypt(string plaintext, string key) {
    string ciphertext = "";

    for (int i = 0, j = 0; i < plaintext.size(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[j % key.size()];

        // Handle spaces
        if (plainChar == ' ') {
            ciphertext += ' ';
            continue; // Skip the rest of the loop for spaces
        }

        // Convert key character to 0-25 range
        keyChar = toupper(keyChar) - 'A';

        // Determine case for decryption
        bool isUpper = isupper(plainChar);

        // Encrypt the character
        char cipherChar = (toupper(plainChar) - 'A' + keyChar) % 26 + 'A';

        // Restore case
        if (!isUpper) {
            cipherChar = tolower(cipherChar);
        }

        ciphertext += cipherChar;
        j++;
    }

    return ciphertext;
}

string polyalphabetic_decrypt(string ciphertext, string key) {
    string plaintext = "";

    for (int i = 0, j = 0; i < ciphertext.size(); i++) {
        char cipherChar = ciphertext[i];
        char keyChar = key[j % key.size()];

        // Handle spaces
        if (cipherChar == ' ') {
            plaintext += ' ';
            continue; // Skip the rest of the loop for spaces
        }

        // Convert key character to 0-25 range
        keyChar = toupper(keyChar) - 'A';

        // Determine case for decryption
        bool isUpper = isupper(cipherChar);

        // Decrypt the character
        char plainChar = (toupper(cipherChar) - 'A' - keyChar + 26) % 26 + 'A';

        // Restore case
        if (!isUpper) {
            plainChar = tolower(plainChar);
        }

        plaintext += plainChar;
        j++;
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
