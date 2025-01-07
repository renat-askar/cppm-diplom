#pragma once

#include "GroundVehicle.hpp"

class Camel: public GroundVehicle
{
	public:
		Camel();

		View getView() const override;

		double getTimeRest(Race* race);

		double getResult(Race* race) override;
};
