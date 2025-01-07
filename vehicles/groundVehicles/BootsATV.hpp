#pragma once

#include "GroundVehicle.hpp"

class BootsATV: public GroundVehicle
{
	public:
		BootsATV();

		View getView() const override;

		double getTimeRest(Race* race);

		double getResult(Race* race) override;
};
