#pragma once
#include "Pilot.h"

class CrazyPilot :
	public Pilot
{
	int secondToStart;
	int tmpPos;
public:
	CrazyPilot(const std::string& newName);
	CrazyPilot(const CrazyPilot& src) = default;
	CrazyPilot(const Pilot& src);

	void generateSecondToStart();
	bool generateAccident();

	std::string getAsString()     const override;
	std::string getTypeAsString() const override;

	bool movement(Racetrack* r) override;
	void reset()                override;
};

