#pragma once
#include "Pilot.h"

class FastPilot :
	public Pilot
{
public:
	FastPilot(const std::string& newName);
	FastPilot(const FastPilot& src) = default;
	FastPilot(const Pilot& src);

	std::string getAsString()     const override;
	std::string getTypeAsString() const override;
};

