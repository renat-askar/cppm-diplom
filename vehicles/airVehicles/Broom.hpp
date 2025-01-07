#pragma once

#include "AirVehicle.hpp"

class Broom: public AirVehicle
{
	public:
		Broom();

		View getView() const override;

		double getDistanceFactor(Race* race) const;

		double getResult(Race* race) override;
};
