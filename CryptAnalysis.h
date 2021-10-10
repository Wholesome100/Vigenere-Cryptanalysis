#pragma once
#include <string>
using namespace std;

class CryptAnalysis
{
public:
	double efreqArray[29] = {1.80, 1.34, 1.31, 10.15, 1.54, 1.49, 4.70, 9.38, 2.03, 2.86, 2.09, 8.43, 0.61, 3.14, 5.28, 8.54, 3.47, 1.92, 1.84, 0.02, 5.82, 6.59, 7.69, 4.48, 2.42, 0.14, 0.16, 0.71, 0.07};
	//double* afreqArray = new double[29];
	//double afreqArray[29];

	void findFrequency(double* aFreqarray);
};

