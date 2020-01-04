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
	Car*        current;
	bool        stopOrder;
	std::string tmpLog;

public:
    Pilot(std::string newName);
	Pilot(const Pilot& src) = default;
	~Pilot() = default;

    std::string getName() const;
    Car*        getCurrentCar() const;
	bool        getStopOrder() const;
	std::string getAsString() const;
	std::string getTypeAsString() const;

	std::string returnLog();
	
	bool        attach(Car* newCar);
	bool        detach();

    friend bool operator==(const Pilot& lhs, const Pilot& rhs);

    friend bool operator!=(const Pilot& lhs, const Pilot& rhs);
};

std::ostream& operator<<(std::ostream& os, const Pilot& p);

