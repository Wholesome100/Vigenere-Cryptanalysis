#include <iostream>
#include <fstream>
#include <cctype>

#include "LanguageLetters.h"
#include "VigenereCrypt.h"
using namespace std;

int main()
{

/*fstream output;
output.open("output.txt");
output << "This is a test of writing to a file.";
output.close();
return 0;*/

//This is the cleantext function
	VigenereCrypt().stripText("textTest.txt");
}


