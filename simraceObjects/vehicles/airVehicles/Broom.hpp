#pragma once

#include "AirVehicle.hpp"

class Broom: public AirVehicle
{
	public:
		Broom();

		View getView() const override;

		double getDistanceFactor(Race* race) const;

		double getReducedDistance(Race* race) const;

		double getResultRaceTime(Race* race) override;
};
