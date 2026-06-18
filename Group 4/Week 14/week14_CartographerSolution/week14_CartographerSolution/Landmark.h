#pragma once
#include "Coordinates.h"
#include <string>
#include <iostream>

class Landmark
{
protected:

	std::string name;
	Coordinates coordinates;
	unsigned threatLevel = -1;

public:

	Landmark() = default;
	Landmark(std::string name, const double x, const double y, const unsigned threatLevel);

	virtual std::string getType() const = 0;
	virtual void print() const = 0;
	virtual std::unique_ptr<Landmark> clone() = 0;

	void setThreatLevel(const unsigned threatLevel);

	std::string getName() const;

	virtual ~Landmark() = default;
};

