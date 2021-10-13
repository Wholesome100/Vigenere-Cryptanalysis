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

	double fileFrequencies[29];
	//double errorC;

	CryptAnalysis:: keyGroup Alpha;
	Alpha.len = 3;

	CryptAnalysis::keyGroup Beta;
	Beta.len = 4;

	CryptAnalysis::keyGroup Gamma;
	Gamma.len = 5;

	CryptAnalysis::keyGroup Winner;

	//cout << "Testing frequency analysis:\n";
	VigenereCrypt().stripText("salad.txt");
	//VigenereCrypt().vigEncrypt("TACOS");
	//VigenereCrypt().vigDecrypt("TQ");
	//CryptAnalysis().findFrequency(charFrequencies, "output.txt");
	//errorC=CryptAnalysis().calculateError(charFrequencies);

	/*CryptAnalysis().findFrequency(fileFrequencies, "cleantext.txt");

	for (int i = 0; i < 29; i++)
	{
		cout << LanguageLetters().refArray[i] << ":";
		cout << fileFrequencies[i] << "\n";
	}*/
	//cout << errorC;

	
	
	Alpha.theoKey = CryptAnalysis().determineKey(Alpha);
	VigenereCrypt().vigDecrypt(Alpha.theoKey);
	CryptAnalysis().findFrequency(fileFrequencies, "output.txt");
	Alpha.errorCalc=CryptAnalysis().calculateError(fileFrequencies);

	Beta.theoKey = CryptAnalysis().determineKey(Beta);
	VigenereCrypt().vigDecrypt(Beta.theoKey);
	CryptAnalysis().findFrequency(fileFrequencies, "output.txt");
	Beta.errorCalc = CryptAnalysis().calculateError(fileFrequencies);

	Gamma.theoKey = CryptAnalysis().determineKey(Gamma);
	VigenereCrypt().vigDecrypt(Gamma.theoKey);
	CryptAnalysis().findFrequency(fileFrequencies, "output.txt");
	Gamma.errorCalc = CryptAnalysis().calculateError(fileFrequencies);

	if (Alpha.errorCalc < Beta.errorCalc && Alpha.errorCalc < Gamma.errorCalc)//Something sussy in here
	{
		Winner = Alpha;
	}
	else if (Beta.errorCalc < Alpha.errorCalc && Beta.errorCalc < Gamma.errorCalc)
	{
		Winner = Beta;
	}
	else if (Gamma.errorCalc < Alpha.errorCalc && Gamma.errorCalc < Beta.errorCalc)
	{
		Winner = Gamma;
	}

	Winner = Gamma;


	cout << "With an error of " << Winner.errorCalc << " the key is most likely " << Winner.theoKey << " of length " << Winner.len<<"\n";
	VigenereCrypt().vigDecrypt(Winner.theoKey);
	cout << "Plaintext written to output.txt\n";
	cout << Alpha.errorCalc << Beta.errorCalc << Gamma.errorCalc;



	//cout << Alpha.len;
}


