#include "VigenereCrypt.h"
#include "LanguageLetters.h"
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

void VigenereCrypt::stripText(string dFile)
{
	char c;

	ifstream input;
	ofstream clean;
	input.open(dFile);
	clean.open("cleantext.txt");

	while (!input.get(c).eof())
	{

		//input.get(c);
		if (!isalpha((unsigned char)c) == false || c == '=' || c == '+' || c == '*')
		{
			clean.put(toupper(c));
		}
	}
	input.close();
	clean.close();
}

void VigenereCrypt::vigEncrypt(string key)
{
	char hold;
	int writ, temp, loopOver=0;
	int* keyRef = new int(key.length());

	//int keyRef[5]={22,3,5,17,21};
	for (int i = 0; i < key.length(); i++)
	{
		keyRef[i] = LanguageLetters().convertAlpha(toupper(key[i]));
		//cout << keyRef[i];
	}

	ifstream input;
	ofstream output;
	input.open("cleantext.txt");
	output.open("output.txt");


	while (!input.get(hold).eof())//Characters are checked every get() call to see if it's the EOF
	{
		//input.get(hold);
		writ = (keyRef[loopOver % key.length()] + LanguageLetters().convertAlpha(hold)) % 29;
		output.put(LanguageLetters().refArray[writ]);
		loopOver++;
	}

	input.close();
	output.close();
}

void VigenereCrypt::vigDecrypt(string key)
{

}
