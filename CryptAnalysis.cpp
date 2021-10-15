#include "CryptAnalysis.h"
#include "LanguageLetters.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

void CryptAnalysis::findFrequency(double* afreqArray, string fileName)
{
	char hold;
	int charCount=0, temp;
	int* freqStore = new int[29];

	for (int i = 0; i < 29; i++)
	{
		freqStore[i] = 0;
	}

	ifstream input;
	input.open(fileName);

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

double CryptAnalysis::calculateError(double* aFreqarray)
{
	double errorCalc=0;

	for (int i = 0; i < 29; i++)
	{
		errorCalc += pow(aFreqarray[i] - CryptAnalysis().efreqArray[i], 2);
	}

	errorCalc = sqrt(errorCalc);
	
	return errorCalc;
}

string CryptAnalysis::determineKey(keyGroup keyG)//I could have determine key take in structs from main via pointer
{
	int charCount = 0, intChar=0, mostFreq, temp;
	char hold;

	char* tempChar = new char[keyG.len+1];
	tempChar[keyG.len] = '\0';

	string keyStore;
	//double arrayAlpha[3][29], 
	double freqStore = 0, partition;

	double** arrayAlpha = new double* [keyG.len];
	{
		for (int i = 0; i < keyG.len; i++)
		{
			arrayAlpha[i] = new double[29];
		}
	}

	for (int j = 0; j < keyG.len; j++)
	{
		for (int i = 0; i < 29; i++)
		{
			arrayAlpha[j][i]=0;
		}
	}

	ifstream input;
	input.open("cleantext.txt");

	while (!input.get(hold).eof())
	{
		intChar = LanguageLetters().convertAlpha(hold);
		arrayAlpha[charCount % keyG.len][intChar] += 1;
		charCount++;
	}

	partition = (charCount / keyG.len);

	for (int j = 0; j < keyG.len; j++)
	{
		for (int i = 0; i < 29; i++)
		{
			arrayAlpha[j][i] /= partition;
			arrayAlpha[j][i] *= 100;
			cout << LanguageLetters().refArray[i]<<":" << arrayAlpha[j][i] << "\n";
		}
		cout << "\n";
	}

	for (int j = 0; j < keyG.len; j++)
	{
		freqStore = 0;
		for (int i = 0; i < 29; i++)
		{
			if (freqStore < arrayAlpha[j][i])
			{
				freqStore = arrayAlpha[j][i];
				mostFreq = i;
			}
		}
		cout << "Most frequent letter is:" << LanguageLetters().refArray[mostFreq]<<"\n";
		cout << "Shift between letter and I is:" << findShift(LanguageLetters().refArray[mostFreq])<<"\n";

		temp = findShift(LanguageLetters().refArray[mostFreq]);//Temp stores the shift value as an integer
		tempChar[j] = LanguageLetters().refArray[temp];//tempChar stores the shift value as a Char from the refArray
		
	}

	//keyStore = tempChar;
	//cout << keyStore;

	//cout << charCount;

	keyStore = tempChar;

	delete[] tempChar;
	for (int i = 0; i < keyG.len; i++)
	{
		delete[] arrayAlpha[i];
	}
	delete[] arrayAlpha;
	
	return keyStore;
}

int CryptAnalysis::findShift(char letter)
{
	int shift;
	shift = ((LanguageLetters().convertAlpha(letter) - LanguageLetters().convertAlpha('A')) + 29) % 29;//Remember to change the letter back to A
	return shift;
}

