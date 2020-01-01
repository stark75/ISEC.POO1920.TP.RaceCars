#pragma once
#include "Car.h"

class RaceResults
{
	Car* competitor;
	int  finishTime;

public:
	RaceResults(Car* c, int fT);
	RaceResults(const RaceResults& src) = default;
	~RaceResults() = default;

	Car*         getCompetitor()       const;
	int          getFinishTime()       const;
	std::string  getAsString()         const;

	friend bool  operator==(RaceResults const& lhs, RaceResults const& rhs);
	friend bool  operator!=(RaceResults const& lhs, RaceResults const& rhs);
	bool         operator<(const RaceResults& other)  const;
	bool         operator>(const RaceResults& other)  const;
	bool         operator<=(const RaceResults& other) const;
	bool         operator>=(const RaceResults& other) const;
};

bool  operator==(RaceResults const& lhs, Car* rhs);
bool  operator!=(RaceResults const& lhs, Car* rhs);
bool  operator==(Car* lhs, RaceResults const& rhs);
bool  operator!=(Car* lhs, RaceResults const& rhs);

std::ostream& operator<<(std::ostream& os, const RaceResults& r);

