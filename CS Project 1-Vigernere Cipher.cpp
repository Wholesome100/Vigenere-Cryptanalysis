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
	string inputFile, key;//Declare variables
	int operation, type=0;

	cout << "What is the name and path of your file?\n";//Get the filename and operation the user wants
	cin >> inputFile;
	cout << "Is this encryption or decryption?(1 or 0)\n";
	cin >> operation;

	if(operation > 1 || operation < 0)//If the user doesnt enter 0 or 1, error out
	{
	cout << "[Invalid operation]";
	return -1;
	}

	if (operation == 0)//If we're decrypting, check if it's keyless
	{
		cout << "Is this keyless decryption?(1=yes or 0=no)\n";
		cin >> type;
	}


	if (type == 1)//If it's keyless then execute the following
	{
		double fileFrequencies[29];//Declare variables
		double lowestError = pow(10, 100);
		int winTrack = 0;

		CryptAnalysis::keyGroup Winner;

		CryptAnalysis::keyGroup keySets[3];//Declare array of structs to test key sizes
		keySets[0].len = 3;
		keySets[1].len = 4;
		keySets[2].len = 5;

		VigenereCrypt().stripText(inputFile);

		for (int i = 0; i < 3; i++)//Loop through the structs
		{
			keySets[i].theoKey = CryptAnalysis().determineKey(keySets[i]);//Get the key
			VigenereCrypt().vigDecrypt(keySets[i].theoKey);//Decrypt using the found key
			CryptAnalysis().findFrequency(fileFrequencies, "output.txt");//Get the frequencies from the decrypted file
			keySets[i].errorCalc = CryptAnalysis().calculateError(fileFrequencies);//Get the error between the actual and expeced frequencies

			if (lowestError >= keySets[i].errorCalc)//If there is a lower error, set lowestError equal to it and store the index of the struct
			{
				lowestError = keySets[i].errorCalc;
				winTrack = i;
			}
		}

		Winner = keySets[winTrack];//Set winner to the struct with lowest error

		cout << "With an error of " << Winner.errorCalc << " the key is most likely " << Winner.theoKey << " of length " << Winner.len << "\n";//Print values and return
		VigenereCrypt().vigDecrypt(Winner.theoKey);
		cout << "Plaintext written to output.txt\n";
		return 0;
	}


	cout << "What is the key?\n";//Take in the key for encrypt/decrypt
	cin >> key;

	if (operation == 1)//Strip the input file and run the encryption algorithim
	{
		VigenereCrypt().stripText(inputFile);
		VigenereCrypt().vigEncrypt(key);
		cout << "Ciphertext written to output.txt";
	}
	else//Strip the input file and run the decryption algorithim
	{
		VigenereCrypt().stripText(inputFile);
		VigenereCrypt().vigDecrypt(key);
		cout << "Plaintext written to output.txt";
	}
}


