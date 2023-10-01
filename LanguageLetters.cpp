#include "LanguageLetters.h"

//convertAlpha takes a character and returns it's index in the refArray
int LanguageLetters::convertAlpha(char letter)
{
for (int i = 0; i < 29; i++) 
{
	if (letter == refArray[i]) //Simple linear search, if refArray[i] matches the character, return the index and break
		{
		return i;
		break;
		}
	}
}
