#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

#include "LanguageLetters.h"
#include "VigenereCrypt.h"
using namespace std;

int main()
{
	string inputFile;
	string key;

	cout << "What is the name and path of your file?\n";
	cin >> inputFile;
	cout << "What is the key?";
	cin >> key;

	VigenereCrypt().stripText(inputFile);
	//VigenereCrypt().vigEncrypt(key);
	VigenereCrypt().vigDecrypt(key);
	cout << "\nCiphertext written to output.txt";
}


