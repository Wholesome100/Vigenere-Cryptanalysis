#pragma once
#include <string>
using namespace std;

class VigenereCrypt
{
public:
	//string ifName;
	//string ofName;

	void vigEncrypt(string key);
	void vigDecrypt(string key);
	void stripText(string dFile);
};

