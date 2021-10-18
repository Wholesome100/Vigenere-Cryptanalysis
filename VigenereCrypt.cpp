#include "VigenereCrypt.h"
#include "LanguageLetters.h"
#include <fstream>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

//stripText reads in a filename and cleans the contents, placing them in cleantext.txt
void VigenereCrypt::stripText(string dFile)
{
	char c;//Char c holds the current file character

	ifstream input;//Streams to open file for read/write
	ofstream clean;
	input.open(dFile);//Open the files
	clean.open("cleantext.txt");

	while (!input.get(c).eof())//check characters every get() call to see if it's the EOF
	{
		if (!isalpha((unsigned char)c) == false || c == '=' || c == '+' || c == '*')//Char c is cast to an unsigned int here to avoid assertation errors
		{
			clean.put(toupper(c));//If char c is a letter of the given alphabet, write it to the cleantext
		}
	}
	input.close();//Close the files when done
	clean.close();
}

//vigEncrypt takes in the key and runs the encryption algorithim on cleantext.txt
void VigenereCrypt::vigEncrypt(string key)
{
	char hold;//hold holds the current file character
	int writ, loopOver=0;//writ is the sum of the two indexes mod 29, loopover increments with each character
	int* keyRef = new int[key.length()];//keyRef is a dynamic array that is as large as the key

	
	for (int i = 0; i < key.length(); i++)//This for loop loops through the key
	{
		keyRef[i] = LanguageLetters().convertAlpha(toupper(key[i]));//At each index i, use convert alpha and place the shift values into the keyRef array
	}

	ifstream input;//ifstream to open file for read
	ofstream output;//ofstream to open file for write
	input.open("cleantext.txt");//open the cleaned text
	output.open("output.txt");//open the output file


	while (!input.get(hold).eof())//Characters are checked every get() call to see if it's the EOF
	{
		writ = (keyRef[loopOver % key.length()] + LanguageLetters().convertAlpha(hold)) % 29;//This is the encryption formula
		output.put(LanguageLetters().refArray[writ]);//Write the letter at position writ in the refArray
		loopOver++;//Increment loopover
	}
	delete[] keyRef;//When done, close the files and delete the allocated array
	input.close();
	output.close();
}

//vigDecrypt takes in the key and runs the decryption algorithim on cleantext.txt
void VigenereCrypt::vigDecrypt(string key)
{

	char hold;//hold holds the current file character
	int writ, loopOver = 0;//writ is the sum of the two indexes mod 29, loopover increments with each character
	int* keyRef = new int[key.length()];//keyRef is a dynamic array that is as large as the key

	
	for (int i = 0; i < key.length(); i++)//This for loop loops through the key
	{
		keyRef[i] = LanguageLetters().convertAlpha(toupper(key[i]));//At each index i, use convert alpha and place the shift values into the keyRef array
	}

	ifstream input;//ifstream to open file for read
	ofstream output;//ofstream to open file for write
	input.open("cleantext.txt");//open the cleaned text
	output.open("output.txt");//open the output file


	while (!input.get(hold).eof())//Like before, characters are checked every get() call to see if it's the EOF
	{
		 writ = (LanguageLetters().convertAlpha(hold) - keyRef[loopOver % key.length()]+29)% 29;//This is the decryption formula
		 
		output.put(LanguageLetters().refArray[writ]);//Write the letter at position writ in the refArray
		loopOver++;//Increment loopover
	}
	delete[] keyRef;//When done, close the files and delete the allocated array
	input.close();
	output.close();

}
