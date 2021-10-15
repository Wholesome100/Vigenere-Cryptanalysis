#pragma once
#include <string>
using namespace std;

class CryptAnalysis
{
public:
	double efreqArray[29] = {1.80, 1.34, 1.31, 10.15, 1.54, 1.49, 4.70, 9.38, 2.03, 2.86, 2.09, 8.43, 0.61, 3.14, 5.28, 8.54, 3.47, 1.92, 1.84, 0.02, 5.82, 6.59, 7.69, 4.48, 2.42, 0.14, 0.16, 0.71, 0.07};
	//double* afreqArray = new double[29];
	//double afreqArray[29];

	//My plan for the actual error checking and analysis is going to be five sets, alpha betha gamma theta lambda, with N set arrays each. Only letters that are mod=0 of the n letter array will be placed in them. Once the frequency analysis is run
	//on the arrays, the hightes occuring letter will be assumed as A, and the shift between them will be calculated. With the shift amount obtained, it will be placed into a n length keyRef array. Once the shifts have been found, the text will be decrypted
	//and error checked. Once all the text from all sets have been checked, the one with the lowest error will be assumed correct

	//function for the sets is going to look like this
	//1.Count the letter occurences for each set and store them in an array
	//2.Divide each letter occurnce by the total number of characters in each set
	//3.Assume the highest frequency character in each set to be 'A'
	//4.Calculate the shift between them and assume it to be the key, and store the shift value in an array
	//5.Decrypt the text using the found key and run findFrequency on it, then calculateError
	//6.Store the calculated error for later
	//7.Once all errors have been found, pick the one with the lowest and assume it's the correct key
	//8. Print out the key length and the determined key, and perform the final decyption

	struct keyGroup
	{
		double errorCalc;
		int len;
		string theoKey="";//I can copy the result from the array into here
	};

	string determineKey(keyGroup keyG);

	int findShift(char letter);

	void findFrequency(double* aFreqarray, string fileName);

	double calculateError(double* aFreqarray);
};

