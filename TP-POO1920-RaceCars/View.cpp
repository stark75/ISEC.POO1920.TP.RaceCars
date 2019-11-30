#include "View.h"
#include <iostream>

void View::printTitle()
{
	std::cout << "________                  _________" << std::endl;
	std::cout << "___  __ \\_____ _____________  ____/_____ _______________" << std::endl;
	std::cout << "__  /_/ /  __ `/  ___/  _ \\  /    _  __ `/_  ___/_  ___/" << std::endl;
	std::cout << "_  _, _// /_/ // /__ /  __/ /___  / /_/ /_  /   _(__  )" << std::endl;
	std::cout << "/_/ |_| \\__,_/ \\___/ \\___/\\____/  \\__,_/ /_/    /____/\n" << std::endl;
	
	std::cout << " _.-.___\\__         _.-.___\\__         _.-.___\\__" << std::endl;
	std::cout << "|  _      _`-.     |  _      _`-.     |  _      _`-." << std::endl;
	std::cout << "'-(_)----(_)--`    '-(_)----(_)--`    '-(_)----(_)--`" << std::endl;
	
	
}

void View::printMessage(std::string message, int type)
{
	std::string output;
	
	if (type == ErrorTypeMessage)
	{
		output = "[ERROR]: ";
		output += message;
	}

	if (type == WarningTypeMessage)
	{
		output = "[WARNING]: ";
		output += message;
	}

	if (type == SuccessTypeMessage)
	{
		output = "[SUCCESS]: ";
		output += message;
	}

	if (type == NullTypeMessage)
	{
		output = message;
	}

	std::cout << output << std::endl;
	
}

void View::printCommandLineMessage()
{
	std::cout << "Introduza um comando: ";
}

void View::helpCommand()
{
	std::cout << "Lista de comandos do modo 1:" << std::endl;
	std::cout << "[1] carregaP <nomeFicheiro>" << std::endl;
	std::cout << "[2] carregaC <nomeFicheiro>" << std::endl;
	std::cout << "[3] carregaA <nomeFicheiro>" << std::endl;
	std::cout << "[4] cria <letraTipo> <dados do objeto>";
	std::cout << "\t\t\tLetras: p - piloto; c - carro; a - autodromo" << std::endl;
	std::cout << "[5] apaga <letraTipo> identificador" << std::endl;
	std::cout << "[6] entranocarro <letraCarro> <nomePiloto> " << std::endl;
	std::cout << "[7] saidocarro <letraCarro>" << std::endl;
	std::cout << "[8] lista" << std::endl;
	std::cout << "[9] modo2" << std::endl;
	std::cout << "[0] SAIR" << std::endl;
}

void View::printInfoCommand(Simulator& s)
{
	s.getDGV()->printCars();
	s.getDGV()->printPilots();
}
