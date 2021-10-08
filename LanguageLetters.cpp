#include "LanguageLetters.h"

int LanguageLetters::convertAlpha(char letter)
{
for (int i = 0; i < 29; i++) 
{
	if (letter == refArray[i]) 
		{
		return i;
		break;
		}
	}
}
