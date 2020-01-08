#pragma once
#include <string>

class Utils
{
public:
	Utils() = delete;
	
	static int argumentCount(std::string str);

	static bool isAlpha(char c);
	static bool isUpper(char c);
	static bool isLower(char c);
	static bool isDigit(char c);
	static bool isNumber(std::string s);

	static std::string toupper(std::string str);
	static std::string tolower(std::string str);
	static std::string doubleToStringWithPrecision(const double value, const int precision = 2);
	static std::string getTimeAsString(int t);

	static int rng(int limit);
	
};