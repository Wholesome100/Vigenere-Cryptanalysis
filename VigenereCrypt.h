#pragma once
#include <string>
using namespace std;

class VigenereCrypt
{
public:
	void vigEncrypt(string key);
	void vigDecrypt(string key);
	void stripText(string dFile);
};

