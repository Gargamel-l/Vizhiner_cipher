#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removeSpaces(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

string vigenereCipherEncrypt(string plaintext, string key) {
    string encryptedText = "";
    int keyLength = key.length();
    int keyIndex = 0;
    for (int i = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            int shift = key[keyIndex % keyLength] - 'A';
            keyIndex++;
            if (islower(plaintext[i])) {
                encryptedText += (plaintext[i] - 'a' + shift) % 26 + 'a';
            }
            else {
                encryptedText += (plaintext[i] - 'A' + shift) % 26 + 'A';
            }
        }
        else {
            encryptedText += plaintext[i];
        }
    }
    return encryptedText;
}

int main() {
    string plaintext;
    string key;

    cout << "Enter the encryption text: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    cin >> key;

    string encryptedText = vigenereCipherEncrypt(plaintext, key);
    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}