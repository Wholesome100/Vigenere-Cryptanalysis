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

	void findFrequency(double* aFreqarray, string fileName);
	double calculateError(double* aFreqarray);
};

