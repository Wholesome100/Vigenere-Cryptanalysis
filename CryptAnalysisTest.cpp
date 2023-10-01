#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cmath>

#include "LanguageLetters.h"
#include "VigenereCrypt.h"
#include "CryptAnalysis.h"


int main()
{
	double fileFrequencies[29];//fileFrequencies stores actual frequencies
	double lowestError = pow(10, 100);//lowestError stores the lowest error
	int winTrack = 0;//winTrack gets the index of the element with the lowest error

	CryptAnalysis::keyGroup Winner;//Winner is set to the struct with the lowest error

	CryptAnalysis::keyGroup keySets[3];//Array of structs, testing for key lengths 3 4 and 5
	keySets[0].len = 3;
	keySets[1].len = 4;
	keySets[2].len = 5;

	VigenereCrypt().stripText("salad.txt");//Put salad.txt in the cleantext

	for (int i = 0; i < 3; i++)//Loop through the elements
	{
		keySets[i].theoKey = CryptAnalysis().determineKey(keySets[i]);//Find the probable key
		VigenereCrypt().vigDecrypt(keySets[i].theoKey);//Decrypt using the found key
		CryptAnalysis().findFrequency(fileFrequencies, "output.txt");//find the frequencies of the decrypted text
		keySets[i].errorCalc = CryptAnalysis().calculateError(fileFrequencies);//Calculate the error

		if (lowestError >= keySets[i].errorCalc)//Check for the lowest error as we go
		{
			lowestError = keySets[i].errorCalc;
			winTrack = i;
		}
	}

	Winner = keySets[winTrack];//Set Winner=element with lowest error

	cout << "With an error of " << Winner.errorCalc << " the key is most likely " << Winner.theoKey << " of length " << Winner.len << "\n";//Print out data and perform the decryption with the most likely key
	VigenereCrypt().vigDecrypt(Winner.theoKey);
	cout << "Plaintext written to output.txt\n";
}