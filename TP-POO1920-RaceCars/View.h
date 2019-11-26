#pragma once
#include <string>

class View
{
	
public:

	enum MessageType
	{
		ErrorType,
		WarningType,
		SuccessType,
		NullType
	};
	
	View() = delete;
	
	static void printTitle();

	static void printMessage(std::string message = "No message.", MessageType type = NullType);
	
};

