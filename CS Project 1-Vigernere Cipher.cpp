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

	double fileFrequencies[29];
	double lowestError=pow(10,100);
	int winTrack=0;

	CryptAnalysis::keyGroup Winner;

	CryptAnalysis::keyGroup keySets[3];//Array of structs
	keySets[0].len=3;
	keySets[1].len=4;
	keySets[2].len=5;

	VigenereCrypt().stripText("salad.txt");

	for(int i=0;i<3;i++)
	{
		keySets[i].theoKey = CryptAnalysis().determineKey(keySets[i]);
		VigenereCrypt().vigDecrypt(keySets[i].theoKey);
		CryptAnalysis().findFrequency(fileFrequencies, "output.txt");
		keySets[i].errorCalc=CryptAnalysis().calculateError(fileFrequencies);

		if(lowestError>= keySets[i].errorCalc)
		{
			lowestError = keySets[i].errorCalc;
			winTrack=i;
		}
	}

	Winner=keySets[winTrack];

	//Winner=keySets[2] //Use this when showing salad.txt off



	/*
	CryptAnalysis:: keyGroup Alpha;
	Alpha.len = 3;

	CryptAnalysis::keyGroup Beta;
	Beta.len = 4;

	CryptAnalysis::keyGroup Gamma;
	Gamma.len = 5;
	*/


	//cout << "Testing frequency analysis:\n";
	//VigenereCrypt().stripText("5eNUDAIM.txt");
	//VigenereCrypt().vigEncrypt("TACOS");
	//VigenereCrypt().vigDecrypt("TQ");
	//CryptAnalysis().findFrequency(charFrequencies, "output.txt");
	//errorC=CryptAnalysis().calculateError(charFrequencies);


	cout << "With an error of " << Winner.errorCalc << " the key is most likely " << Winner.theoKey << " of length " << Winner.len<<"\n";
	VigenereCrypt().vigDecrypt(Winner.theoKey);
	cout << "Plaintext written to output.txt\n";
	//cout << Alpha.errorCalc << Beta.errorCalc << Gamma.errorCalc;

	/*
	CryptAnalysis().findFrequency(fileFrequencies, "cleantext.txt");

	for (int i = 0; i < 29; i++)
	{
		cout << LanguageLetters().refArray[i] << ":";
		cout << fileFrequencies[i] << "\n";
	}
	//cout << errorC;
	*/
}


