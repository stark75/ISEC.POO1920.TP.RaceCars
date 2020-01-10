#pragma once
#include <iostream>
#include <vector>

class Car;
class Racetrack;

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
    virtual ~Pilot() = default;
	virtual Pilot* duplicate() const = 0;

    std::string         getName()         const;
    Car*                getCurrentCar()   const;
	bool                getStopOrder()    const;
	virtual std::string getAsString()     const;
	virtual std::string getTypeAsString() const;

	void                setLog(const std::string& newMessage);
	void                setStop(const bool& condition);

	std::string  returnLog();
	
	bool         attach(Car* newCar);
	bool         detach();

	virtual bool movement(Racetrack* r) = 0;
	virtual void reset()                = 0;

    friend bool  operator==(const Pilot& lhs, const Pilot& rhs);

    friend bool  operator!=(const Pilot& lhs, const Pilot& rhs);
};

std::ostream& operator<<(std::ostream& os, const Pilot& p);

