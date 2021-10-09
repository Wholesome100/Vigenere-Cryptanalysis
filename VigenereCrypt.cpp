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
	char hold;//hold holds the current file character
	int writ, loopOver=0;//writ is the sum of the two indexes mod 29, loopover increments with each character
	int* keyRef = new int[key.length()];//keyRef is a dynamic array that is as large as the key

	//int keyRef[5]={22,3,5,17,21};
	for (int i = 0; i < key.length(); i++)//This for loop loops through the key
	{
		keyRef[i] = LanguageLetters().convertAlpha(toupper(key[i]));//At each index i, use convert alpha and place the shift values into the keyRef array
		//cout << keyRef[i];
	}

	ifstream input;//ifstream to open file for red
	ofstream output;//ofstream to open file for write
	input.open("cleantext.txt");//open the cleaned text
	output.open("output.txt");//write to the output file


	while (!input.get(hold).eof())//Characters are checked every get() call to see if it's the EOF
	{
		//input.get(hold);
		writ = (keyRef[loopOver % key.length()] + LanguageLetters().convertAlpha(hold)) % 29;//This is the encryption formula
		output.put(LanguageLetters().refArray[writ]);//Write the letter at position writ in th refArray
		loopOver++;//Increment loopover
	}
	delete[] keyRef;//When done, close the files and delete the allocated array
	input.close();
	output.close();
}

void VigenereCrypt::vigDecrypt(string key)
{

	char hold;//hold holds the current file character
	int writ, loopOver = 0;//writ is the sum of the two indexes mod 29, loopover increments with each character
	int* keyRef = new int[key.length()];//keyRef is a dynamic array that is as large as the key

	//int keyRef[5]={22,3,5,17,21};
	for (int i = 0; i < key.length(); i++)//This for loop loops through the key
	{
		keyRef[i] = LanguageLetters().convertAlpha(toupper(key[i]));//At each index i, use convert alpha and place the shift values into the keyRef array
		//cout << keyRef[i];
	}

	ifstream input;//ifstream to open file for red
	ofstream output;//ofstream to open file for write
	input.open("cleantext.txt");//open the cleaned text
	output.open("output.txt");//write to the output file


	while (!input.get(hold).eof())//Characters are checked every get() call to see if it's the EOF
	{
		//input.get(hold);
		
		
		 //writ = (keyRef[loopOver % key.length()] - LanguageLetters().convertAlpha(hold));//This is the encryption formula
		 writ = (LanguageLetters().convertAlpha(hold) - keyRef[loopOver % key.length()]+29)% 29;
		 
		
		output.put(LanguageLetters().refArray[writ]);//Write the letter at position writ in th refArray
		loopOver++;//Increment loopover
	}
	delete[] keyRef;//When done, close the files and delete the allocated array
	input.close();
	output.close();

}
