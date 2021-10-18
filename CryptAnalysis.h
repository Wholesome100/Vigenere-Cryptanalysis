#pragma once
#include <string>
using namespace std;

class CryptAnalysis
{
public:
	//efreqArray stores the values for the expected frequencies of the letters in the language
	double efreqArray[29] = {1.80, 1.34, 1.31, 10.15, 1.54, 1.49, 4.70, 9.38, 2.03, 2.86, 2.09, 8.43, 0.61, 3.14, 5.28, 8.54, 3.47, 1.92, 1.84, 0.02, 5.82, 6.59, 7.69, 4.48, 2.42, 0.14, 0.16, 0.71, 0.07};

	//keyGroup is a struct that stores 3 things: len which is the length of the tested key, theoKey which is the found key of length len, 
	//and errorCalc which is the error found using the least squares method between the expected and actual character frequencies
	struct keyGroup
	{
		double errorCalc;
		int len;
		string theoKey;//I can copy the result from the array into here
	};

	string determineKey(keyGroup keyG);

	int findShift(char letter);

	void findFrequency(double* aFreqarray, string fileName);

	double calculateError(double* aFreqarray);
};

