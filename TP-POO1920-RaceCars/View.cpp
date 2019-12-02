#include "View.h"
#include <iostream>
#include "Consola/consola.h"

void View::printTitle()
{
	Consola::setTextColor(Consola::VERDE);
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
		Consola::setTextColor(Consola::VERMELHO_CLARO);
		output = "[ERROR]: ";
		Consola::setTextColor(Consola::VERDE);
		output += message;
	}

	if (type == WarningTypeMessage)
	{
		Consola::setTextColor(Consola::AMARELO_CLARO);
		output = "[WARNING]: ";
		Consola::setTextColor(Consola::VERDE);
		output += message;
	}

	if (type == SuccessTypeMessage)
	{
		Consola::setTextColor(Consola::VERDE_CLARO);
		output = "[SUCCESS]: ";
		Consola::setTextColor(Consola::VERDE);
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
	std::cout << "carregaP <nomeFicheiro>" << std::endl;
	std::cout << "carregaC <nomeFicheiro>" << std::endl;
	std::cout << "carregaA <nomeFicheiro>" << std::endl;
	std::cout << "cria <letraTipo> <dados do objeto>";
	std::cout << "          Letras: p - piloto; c - carro; a - autodromo" << std::endl;
	std::cout << "apaga <letraTipo> identificador" << std::endl;
	std::cout << "entranocarro <letraCarro> <nomePiloto> " << std::endl;
	std::cout << "saidocarro <letraCarro>" << std::endl;
	std::cout << "lista" << std::endl;
	std::cout << "campeonato" << std::endl;
	std::cout << "sair" << std::endl;
}

void View::printInfoCommand(Simulator& s)
{
	s.getDGV()->printCars();
	s.getDGV()->printPilots();
	s.printRacetracks();
}

void View::printRace(Racetrack* r)
{
	Consola::clrscr();
	int length = r->getTrackLength();
	std::vector<Car* > raceCars = r->getCarsInTrack();
	int raceSize = raceCars.size();

	if (raceSize == 0)
		return;

	
	for (int i=0; i<raceSize;i++)
	{
		Consola::gotoxy(25, 3 + i);
		Consola::gotoxy(4, 3+i);
		char tmpChar = raceCars[i]->getID();
		int  tmpPos = raceCars[i]->getPosition();

		int num = ((tmpPos / length) * 20) + 1;

		if (i % 2 == 0)
		{
			Consola::setTextColor(Consola::AZUL_CLARO);
		}
		
		for(int y = 0; y< num; y++)
		{
			std::cout << tmpChar << std::endl;
		}

			
		
		Consola::setTextColor(Consola::VERDE);
		
	}
	Consola::getch();
}
