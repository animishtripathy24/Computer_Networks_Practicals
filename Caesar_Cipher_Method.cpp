#include<iostream>
using namespace std;

string encrypt(string& text, int key)
{
    string result;

    for (int i = 0; i < text.length(); i++) {

        if (isupper(text[i]))
            result += char(int(text[i] + key - 65) % 26 + 65);

        // Encrypt Lowercase letters
        else
            result += char(int(text[i] + key - 97) % 26 + 97);
    }

    return result;
}
string decrypt(string& cipher, int key)
{
    string result;

    for (int i = 0; i < cipher.length(); i++) {

        if (isupper(cipher[i]))
        {
            int value = cipher[i] - 'A';
            value = (value + 26 - key) % 26;
            char decrypted_letter = value + 'A';
            result.push_back(decrypted_letter);
        }
        // Encrypt Lowercase letters
        else
        {
            int value = cipher[i] - 'a';
            value = (value + 26 - key) % 26;
            char decrypted_letter = value + 'a';
            result.push_back(decrypted_letter);
        }
    }

    return result;
}
int main()
{
    cout << "Enter the plain text " << endl;
    string plain;
    cin >> plain;
    cout << endl << "Enter the key places too be shifted" << endl;
    int key;
    cin >> key;
    string cipher=encrypt(plain,key);
    cout << "The encrypted string is " << endl;
    cout << cipher << endl;
    cout << "Enter the string at the receiver side" <<endl;
    string receiver;
    cin >> receiver;
    cout << "The string at the receiver side is " << receiver << endl;
    //now we have to decrypt the receiver string 
    string realString=decrypt(cipher,key);
    cout << "The Real string is " << realString << endl;
    //now comparing the ciphered string and the original string
    int comp=realString.compare(plain);
    if(comp==0)
    {
        cout << "No attack on the message " << endl;
    }
    else
    {
        cout << "There is a attack on the message " << endl;
    }

}

