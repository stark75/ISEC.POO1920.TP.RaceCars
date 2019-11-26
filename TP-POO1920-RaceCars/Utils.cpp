#include "Utils.h"
#include <iostream>

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
			if(isLower(str[i])) tmpString += std::to_string(::toupper(str[i]));
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
			if (isUpper(str[i])) tmpString += std::to_string(::tolower(str[i]));
		}
	}

	return tmpString;
}

void Utils::printError(std::string errorMessage)
{
	std::cout << "Erro: " << errorMessage << "\nEncerrando o Programa." << std::endl;
	exit(0);
}
