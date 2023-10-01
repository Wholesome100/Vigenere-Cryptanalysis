#include "CryptAnalysis.h"
#include "LanguageLetters.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

//findFrequency takes in a pointer to an array, and a filename
void CryptAnalysis::findFrequency(double* afreqArray, string fileName)
{
	char hold;//Variables, hold to hold the current char, charCount for total chars, temp for holding indexes, and freqstore to record occurences
	int charCount=0, temp;
	int* freqStore = new int[29];

	for (int i = 0; i < 29; i++)//Initialize elements in freqStore
	{
		freqStore[i] = 0;
	}

	ifstream input;//Open file for reading
	input.open(fileName);

	while (!input.get(hold).eof())//While the character is not the EOF, increase the occurrence of current letter at it's index in freqStore
	{
		temp = LanguageLetters().convertAlpha(hold);
		freqStore[temp] += 1;
		charCount++;//Increment total characters
	}

	for (int i = 0; i < 29; i++)//Divide the occurences in the freqStore by the total # of characters and multiply by 100 to get the actual frequencies, storing them in the afreqArray
	{
		afreqArray[i] = (freqStore[i] / static_cast<double>(charCount)) * 100;
	}

	input.close();//When done, close the file and delete freqStore
	delete[] freqStore;
}



//calculateError takes in a pointer to an array, and returns the error as a double
double CryptAnalysis::calculateError(double* aFreqarray)
{
	double errorCalc=0;//Initialize errorCalc

	for (int i = 0; i < 29; i++)//For loop gives the summation of the actual frequency - the expected frequency squared
	{
		errorCalc += pow(aFreqarray[i] - CryptAnalysis().efreqArray[i], 2);
	}

	errorCalc = sqrt(errorCalc);//Square root the summation per the formula

	return errorCalc;//Return the error
}



//determineKey takes in a keyGroup struct and returns the found key as a string
string CryptAnalysis::determineKey(keyGroup keyG)
{
	int charCount = 0, intChar=0, mostFreq, temp;//Declare variables
	char hold;

	char* tempChar = new char[keyG.len+1];//Declare a dynamic character array to hold the key
	tempChar[keyG.len] = '\0';

	string keyStore;//Declare variables
	double freqStore = 0, partition;

	double** arrayAlpha = new double* [keyG.len];//Declare a dynamic 2d array with len many rows
	{
		for (int i = 0; i < keyG.len; i++)//Pointer arrays to hold alphabet letters
		{
			arrayAlpha[i] = new double[29];
		}
	}

	for (int j = 0; j < keyG.len; j++)//Initialize all the row/column elements
	{
		for (int i = 0; i < 29; i++)
		{
			arrayAlpha[j][i]=0;
		}
	}

	ifstream input;//Open cleantext.txt for reading
	input.open("cleantext.txt");

	while (!input.get(hold).eof())
	{
		intChar = LanguageLetters().convertAlpha(hold);//get the index of the current letter
		arrayAlpha[charCount % keyG.len][intChar] += 1;//charCount is modded over the key length, so for len=3, each letter occurrence will be recorded into a 1st, 2nd, or 3rd 'group'
		charCount++;//Increment total characters
	}

	partition = (charCount / keyG.len);//Divide total characters by the len, represents total characters in each 'group'

	for (int j = 0; j < keyG.len; j++)
	{
		for (int i = 0; i < 29; i++)
		{
			arrayAlpha[j][i] /= partition;//Divide the occurences for each group by the partition value
			arrayAlpha[j][i] *= 100;//Multiply by 100 to get the frequencies
		}
	}

	for (int j = 0; j < keyG.len; j++)
	{
		freqStore = 0;//Initialize freqStore

		for (int i = 0; i < 29; i++)
		{
			if (freqStore < arrayAlpha[j][i])//Go through each letter and find the most frequent
			{
				freqStore = arrayAlpha[j][i];
				mostFreq = i;
			}
		}

		temp = findShift(LanguageLetters().refArray[mostFreq]);//Temp stores the shift value as an integer
		tempChar[j] = LanguageLetters().refArray[temp];//tempChar stores the shift value as a Char from the refArray
	}


	keyStore = tempChar;//Set string keyStore equal to tempChar

	delete[] tempChar;//When done, delete allocated variables and close the input file
	for (int i = 0; i < keyG.len; i++)
	{
		delete[] arrayAlpha[i];
	}
	delete[] arrayAlpha;
	input.close();

	return keyStore;//Return the found key
}



//findShift takes in the most frequent character, assumes it to be A, and returns the shift between them
int CryptAnalysis::findShift(char letter)
{
	int shift;
	shift = ((LanguageLetters().convertAlpha(letter) - LanguageLetters().convertAlpha('A')) + 29) % 29;//Equation to find the key letter as the shift between the most frequent character and A
	return shift;//Return the shift value of the key letter
}

