#include "VigenereCrypt.h"
#include <fstream>
#include <cctype>

using namespace std;

void VigenereCrypt::stripText(string dFile)
{
	char c;

	ifstream input;
	ofstream clean;
	input.open(dFile);
	clean.open("cleantext.txt");

	while (!input.eof())
	{

		input.get(c);
		if (!isalpha((unsigned char)c) == false || c == '=' || c == '+' || c == '*')
		{
			clean.put(toupper(c));
		}
	}
	input.close();
	clean.close();
}
