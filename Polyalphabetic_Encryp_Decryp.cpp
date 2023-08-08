#include <bits/stdc++.h>
using namespace std;

string polyalphabetic_encrypt(string plaintext, string key) {
    string ciphertext = "";
    
    for (int i = 0; i < plaintext.size(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[i % key.size()];

        // Convert key character to 0-25 range
        keyChar = toupper(keyChar) - 'A';

        // Encrypt the character
        char cipherChar = (toupper(plainChar) - 'A' + keyChar) % 26 + 'A';
        ciphertext += cipherChar;
    }
    
    return ciphertext;
}

string polyalphabetic_decrypt(string ciphertext, string key) {
    string plaintext = "";
    
    for (int i = 0; i < ciphertext.size(); i++) {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % key.size()];

        // Convert key character to 0-25 range
        keyChar = toupper(keyChar) - 'A';

        // Decrypt the character
        char plainChar = (toupper(cipherChar) - 'A' - keyChar + 26) % 26 + 'A';
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
