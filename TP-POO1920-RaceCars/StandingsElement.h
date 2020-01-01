#pragma once
#include "Car.h"

class StandingsElement
{
	Car* competitor;
	int  score;

public:
	StandingsElement(Car* c);
	StandingsElement(const StandingsElement& src) = default;
	~StandingsElement() = default;

	Car* getCompetitor()       const;
	int  getScore()            const;
	std::string  getAsString() const;

	void increaseScore(int value);

	friend bool  operator==(StandingsElement const& lhs, StandingsElement const& rhs);
	friend bool  operator!=(StandingsElement const& lhs, StandingsElement const& rhs);
	bool         operator<(const StandingsElement& other)  const;
	bool         operator>(const StandingsElement& other)  const;
	bool         operator<=(const StandingsElement& other) const;
	bool         operator>=(const StandingsElement& other) const;
};

bool  operator==(StandingsElement const& lhs, Car* rhs);
bool  operator!=(StandingsElement const& lhs, Car* rhs);
bool  operator==(Car* lhs, StandingsElement const& rhs);
bool  operator!=(Car* lhs, StandingsElement const& rhs);

std::ostream& operator<<(std::ostream& os, const StandingsElement& sE);