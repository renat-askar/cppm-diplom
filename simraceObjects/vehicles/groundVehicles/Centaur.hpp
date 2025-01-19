#pragma once

#include "GroundVehicle.hpp"

class Centaur: public GroundVehicle
{
	public:
		Centaur();

		View getView() const override;

		double getTimeRest(Race* race);

		double getResultRaceTime(Race* race) override;
};
