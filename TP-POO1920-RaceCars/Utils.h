#pragma once
#include <string>

class Utils
{
public:
	Utils() = delete;
	
	int argumentCount(std::string str);

	bool isAlpha(char c);
	bool isUpper(char c);
	bool isLower(char c);
	bool isDigit(char c);
	bool isNumber(std::string s);

	std::string toupper(std::string str);
	std::string tolower(std::string str);

	void printError(std::string errorMessage = "No message.");
};