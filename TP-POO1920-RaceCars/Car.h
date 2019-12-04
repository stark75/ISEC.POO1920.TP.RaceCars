#pragma once
#include <string>
#include "Pilot.h"

class Pilot;

class Car
{
	//Car ID
	static char  nextID;
	std::string  brand;
	std::string  model;
	char id;

	//Car Specs
	const double maxEnergy;
	const int    maxSpeed;

	//Car Stats
	int          speed;
	double       energy;
	bool         movement;
	int          accelerationPedal;
	int          brakePedal;
	int          time;
	int          position;
	bool         emergencySignal;
	bool         isDamaged;
	Pilot*       driver;
	
public:
	Car(int e, int mE, int mS,std::string b, std::string m = "Base");
	Car(const Car& src);
	~Car() = default;

	//Getters
	char         getNextID()            const;
	std::string  getBrand()             const;
	std::string  getModel()             const;
	char         getID()                const;
	double       getMaxEnergy()         const;
	int          getMaxSpeed()          const;
	Pilot*       getDriver()            const;
	double       getEnergy()            const;
	int          getSpeed()             const;
	int          getTime()              const;
	int          getPosition()          const;
	bool         getMovement()          const;
	int          getAccelerationPedal() const;
	int          getBrakePedal()        const;
	bool         getEmergencySignal()   const;
	bool         getDamage()            const;

	void         setPosition(int newPos);
	bool         attach(Pilot* newDriver);
	bool         detach();
	
	std::string  getAsString()          const;

	bool         pressAccelerate(int times = 1); //! Check
	bool         pressBrake(int times = 1); //! Check
	bool         energyCharge(int n);
	bool         energyFullCharge();
	bool         energyConsumption();
	void         move(int n);
	//TODO: Car movement

	friend bool  operator==(Car const& lhs, Car const& rhs);
	friend bool  operator!=(Car const& lhs, Car const& rhs);
	bool         operator<(const Car& other) const;
	bool         operator>(const Car& other) const;
	bool         operator<=(const Car& other) const;
	bool         operator>=(const Car& other) const;
};


bool  operator==(Car* const& lhs, Car  const& rhs);
bool  operator!=(Car* const& lhs, Car  const& rhs);
bool  operator==(Car  const& lhs, Car* const& rhs);
bool  operator!=(Car  const& lhs, Car* const& rhs);

std::ostream&    operator<<(std::ostream& os, const Car& c);
