#pragma once
#include "Landmark.h"

class Settlement : public Landmark
{

private:
	int population = 0;

protected:

	Settlement() = default;
	Settlement(std::string name, const double x, const double y,
		const unsigned threatLevel, const int population);

	virtual std::string getType() const override;
	virtual void print() const override;
	virtual std::unique_ptr<Landmark> clone() override;

};

