// Section 10
// Challenge - 
// Substitution Cipher

/*
A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decryped the encrypted message back to the original message.

You may use the 2 strings below for  your subsitition.
For example, to encrypt you can replace the character at position n in alphabet 
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.

Have fun! And make the cipher stronger if you wish!
Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
forth. Also, currently the cipher always substitutes a lowercase letter with an uppercase letter and vice-versa.
This could also be improved.

Remember, the less code you write the less code you have to test!
Reuse existing functionality in libraries and in the std::string class!
*/

#include <iostream>

using namespace std;
int main() 
{
  string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
  
  string message {};
  cout << "Enter the secret message: ";
  getline(cin, message);

  cout << "\nEncrypting message...\n";
  string encrypted {};
  for (char c: message)
  {
    size_t charPos = alphabet.find(c,0);
    if (charPos != string::npos)
      encrypted += key.at(charPos);
    else
      encrypted += c;
  }
  cout << "\nEncrypted message: " << encrypted << endl;

  cout << "\nDecrypting message...\n";
  string decrypted {};
  for (char c: encrypted)
  {
    size_t charPos = key.find(c,0);
    if (charPos != string::npos)
      decrypted += alphabet.at(charPos);
    else
      decrypted += c;
  }
  cout << "\nDecrypted message: " << decrypted << endl;

  return 0;
}

