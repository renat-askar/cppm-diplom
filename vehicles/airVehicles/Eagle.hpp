#pragma once

#include "AirVehicle.hpp"

class Eagle: public AirVehicle
{
	public:
		Eagle();

		View getView() const override;

		double getDistanceFactor(Race* race) const;

		double getReducedDistance(Race* race) const;

		double getResultRaceTime(Race* race) override;
};