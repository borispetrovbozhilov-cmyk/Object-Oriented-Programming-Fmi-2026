#pragma once
#pragma once
#include "Coordinates.h"
#include <string>
#include <iostream>
#include <vector>

#include "Landmark.h"
#include "Settlement.h"
#include "Dungeon.h"
#include "NaturalFeature.h"
#include "Ruin.h"

class Territory
{
protected:

	std::vector<std::unique_ptr<Landmark>> landmarks;

public:

	void addLandmark(std::unique_ptr<Landmark> landmark);
	std::unique_ptr<Landmark> removeLandmark(const std::string& name);
	void setDangetLevel(const int dangerLevel);
	bool hasLandmark(const std::string& name);
	void print();
};

