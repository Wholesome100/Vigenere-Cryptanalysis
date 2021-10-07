// CS Project 1-Vigernere Cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{

/*fstream output;
output.open("output.txt");
output << "This is a test of writing to a file.";
output.close();
return 0;*/

char c;

ifstream input;
input.open("nuDAim.txt");
while (!input.eof())
{
	input.get(c);
	cout << c;
}
input.close();
}


