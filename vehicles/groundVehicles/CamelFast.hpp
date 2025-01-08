#pragma once

#include "GroundVehicle.hpp"

class CamelFast: public GroundVehicle
{
	public:
		CamelFast();

		View getView() const override;

		double getTimeRest(Race* race);

		double getResultRaceTime(Race* race) override;
};
