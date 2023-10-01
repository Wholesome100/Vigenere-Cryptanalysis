#include "VigenereCrypt.h"
#include "LanguageLetters.h"
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	VigenereCrypt().stripText("textTest.txt");//Cleans the text for use by removing invalid characters and white space
	cout << "Cleaned text placed in cleantext.txt" << endl;
	VigenereCrypt().vigEncrypt("USA");//Encrypts the plaintext inside cleantext.txt using key USA
	cout << "Text Encrypted using key USA, ciphertext written to output.txt" << endl;
}