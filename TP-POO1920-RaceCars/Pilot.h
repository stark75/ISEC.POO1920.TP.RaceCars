#pragma once
#include <iostream>
#include <vector>

class Car;

class Pilot
{
    //Pilot ID
    std::string name; //TODO: Name is unique per pilot
	static std::vector<std::string> pilotNames;
    
	//Pilot Status
	Car* current;

public:
    Pilot(std::string newName);
	Pilot(const Pilot& src);
	~Pilot();


    std::string getName() const;
    Car*        getCurrentCar() const;
	std::string getAsString() const;

	bool        attach(Car* newCar);
	bool        detach();

    friend bool operator==(const Pilot& lhs, const Pilot& rhs);

    friend bool operator!=(const Pilot& lhs, const Pilot& rhs);
};

std::ostream& operator<<(std::ostream& os, const Pilot& p);

