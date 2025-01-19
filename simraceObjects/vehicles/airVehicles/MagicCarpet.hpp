#pragma once

#include "AirVehicle.hpp"

class MagicCarpet: public AirVehicle
{
	public:
		MagicCarpet();

		View getView() const override;

		double getDistanceFactor(Race* race) const;

		double getReducedDistance(Race* race) const;

		double getResultRaceTime(Race* race) override;
};
