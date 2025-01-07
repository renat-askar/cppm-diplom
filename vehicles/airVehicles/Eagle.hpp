#pragma once

#include "AirVehicle.hpp"

class Eagle: public AirVehicle
{
	public:
		Eagle();

		View getView() const override;

		double getDistanceFactor(Race* race) const;

		double getResult(Race* race) override;
};