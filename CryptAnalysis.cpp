#include "CryptAnalysis.h"
#include "LanguageLetters.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

void CryptAnalysis::findFrequency(double* afreqArray)
{
	char hold;
	int charCount=0, temp;
	int* freqStore = new int[29];

	for (int i = 0; i < 29; i++)
	{
		freqStore[i] = 0;
	}

	ifstream input;
	input.open("cleantext.txt");

	while (!input.get(hold).eof())
	{
		temp = LanguageLetters().convertAlpha(hold);
		freqStore[temp] += 1;
		charCount++;
	}

	for (int i = 0; i < 29; i++)
	{
		//cout << freqStore[i] << "\n";
		afreqArray[i] = (freqStore[i] / static_cast<double>(charCount)) * 100;
		//cout << afreqArray[i]<<"\n";
	}
	//cout << charCount;

	input.close();
	delete[] freqStore;
}
