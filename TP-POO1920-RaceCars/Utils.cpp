#include "Utils.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

int Utils::argumentCount(std::string str)
{
	int strArguments = 0;
	for (int i = 0; i < int(str.length()); i++)
	{
		if (i == 0)
		{
			if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			{
				++strArguments;
			}
		}
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && i + 1 != int(str.length()))
		{
			if (str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\n')
			{
				++strArguments;
			}
		}
	}
	return strArguments;
}

bool Utils::isAlpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

bool Utils::isUpper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

bool Utils::isLower(char c)
{
	return (c >= 'a' && c <= 'z');
}

bool Utils::isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool Utils::isNumber(std::string s)
{
	for (int i = 0; i < static_cast<int>(s.size()); i++)
	{
		if (!isDigit(s[i]))
		{
			return false;
		}
	}

	return true;
}

std::string Utils::toupper(std::string str)
{
	std::string tmpString;
	for (int i = 0; i < static_cast<int>(str.length()); i++)
	{
		if (isAlpha(str[i]))
		{
			if(isLower(str[i])) tmpString += ::toupper(str[i]);
			else tmpString += str[i];
		}
	}

	return tmpString;
}

std::string Utils::tolower(std::string str)
{
	std::string tmpString;
	for (int i = 0; i < static_cast<int>(str.length()); i++)
	{
		if (isAlpha(str[i]))
		{
			if (isUpper(str[i])) tmpString += ::tolower(str[i]);
			else tmpString += str[i];
		}
	}

	return tmpString;
}

std::string Utils::doubleToStringWithPrecision(const double value, const int precision)
{
	std::ostringstream out;
	out.precision(precision);
	out << std::fixed << value;
	return out.str();
}

std::string Utils::getTimeAsString(int t)
{
	std::string time;
	if (t < 0)
		return "Invalid Time";
	if (t < 60)
	{
		time += std::to_string(t);
		time += "s";
	}
	if(t >= 60)
	{
		int integer = t;
		int seconds;
		int minutes;
		int hours = 0;
		int days = 0;
		
		for (minutes = 0; integer > 59; minutes++)
		{
			integer -= 60;
		}

		seconds = integer;

		if(minutes >= 60)
		{
			integer = minutes;
		
			for(; integer > 59; hours++)
			{
				integer -= 60;
			}

			minutes = integer;

			if(hours > 23)
			{
				integer = hours;

				for(;integer > 23; days++)
				{
					integer -= 24;
				}

				hours = integer;
			}
			
		}

		if (days > 0)
		{
			time += std::to_string(days);
			time += ":";
		}

		if (hours > 0)
		{
			if (hours < 10)
				time += "0";
			time += std::to_string(hours);
			time += ":";
		}

		if (minutes < 10)
			time += "0";

		time += std::to_string(minutes);
		time += ":";
		
		if (seconds < 10)
			time += "0";

		time += std::to_string(seconds);
	}

	return time;
}

int Utils::rng(int max)
{
	std::srand((unsigned)time(nullptr));

	int num = (rand() % max) + 1;

	return num;
}
