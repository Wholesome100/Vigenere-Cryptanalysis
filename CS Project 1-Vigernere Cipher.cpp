#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

#include "LanguageLetters.h"
#include "VigenereCrypt.h"
#include "CryptAnalysis.h"
using namespace std;

int main()
{
	/*string inputFile;
	string key;

	cout << "What is the name and path of your file?\n";
	cin >> inputFile;
	cout << "What is the key?";
	cin >> key;

	VigenereCrypt().stripText(inputFile);
	VigenereCrypt().vigEncrypt(key);
	//VigenereCrypt().vigDecrypt(key);
	cout << "\nCiphertext written to output.txt";*/

	double charFrequencies[29];
	double errorC;

	cout << "Testing frequency analysis:\n";
	VigenereCrypt().stripText("encryptedNUDAIM.txt");
	//VigenereCrypt().vigEncrypt("TA");
	VigenereCrypt().vigDecrypt("T");
	CryptAnalysis().findFrequency(charFrequencies, "output.txt");
	errorC=CryptAnalysis().calculateError(charFrequencies);

	for (int i = 0; i < 29; i++)
	{
		cout << LanguageLetters().refArray[i] << ":";
		cout << charFrequencies[i] << "\n";
	}
	cout << errorC;
}


