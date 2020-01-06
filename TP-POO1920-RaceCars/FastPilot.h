#pragma once
#include "Pilot.h"

class FastPilot :
	public Pilot
{
public:
	FastPilot(const std::string& newName);
	FastPilot(const FastPilot& src) = default;
	FastPilot(const Pilot& src);
	bool generatePanicAttack(int raceTime);

	std::string getAsString()     const override;
	std::string getTypeAsString() const override;

	bool movement(Racetrack* r) override;
	void reset() override;
};

