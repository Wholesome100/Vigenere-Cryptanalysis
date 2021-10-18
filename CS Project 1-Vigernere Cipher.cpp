#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cmath>

#include "LanguageLetters.h"
#include "VigenereCrypt.h"
#include "CryptAnalysis.h"
using namespace std;

int main()
{
	string inputFile, key;
	int operation, type=0;

	cout << "What is the name and path of your file?\n";
	cin >> inputFile;
	cout << "Is this encryption or decryption?(1 or 0)\n";
	cin >> operation;

	if(operation > 1 || operation < 0)
	{
	cout << "[Invalid operation]";
	return -1;
	}

	if (operation == 0)
	{
		cout << "Is this keyless decryption?(1=yes or 0=no)\n";
		cin >> type;
	}


	if (type == 1)
	{
		double fileFrequencies[29];
		double lowestError = pow(10, 100);
		int winTrack = 0;

		CryptAnalysis::keyGroup Winner;

		CryptAnalysis::keyGroup keySets[3];//Array of structs
		keySets[0].len = 3;
		keySets[1].len = 4;
		keySets[2].len = 5;

		VigenereCrypt().stripText("salad.txt");

		for (int i = 0; i < 3; i++)
		{
			keySets[i].theoKey = CryptAnalysis().determineKey(keySets[i]);
			VigenereCrypt().vigDecrypt(keySets[i].theoKey);
			CryptAnalysis().findFrequency(fileFrequencies, "output.txt");
			keySets[i].errorCalc = CryptAnalysis().calculateError(fileFrequencies);

			if (lowestError >= keySets[i].errorCalc)
			{
				lowestError = keySets[i].errorCalc;
				winTrack = i;
			}
		}

		Winner = keySets[winTrack];

		cout << "With an error of " << Winner.errorCalc << " the key is most likely " << Winner.theoKey << " of length " << Winner.len << "\n";
		VigenereCrypt().vigDecrypt(Winner.theoKey);
		cout << "Plaintext written to output.txt\n";
		return 0;
	}


	cout << "What is the key?\n";
	cin >> key;

	if (operation == 1)
	{
		VigenereCrypt().stripText(inputFile);
		VigenereCrypt().vigEncrypt(key);
		cout << "Ciphertext written to output.txt";
	}
	else
	{
		VigenereCrypt().stripText(inputFile);
		VigenereCrypt().vigDecrypt(key);
		cout << "Plaintext written to output.txt";
	}
}


