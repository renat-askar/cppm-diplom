#pragma once

#include "AirVehicle.hpp"

class Eagle: public AirVehicle
{
	public:
		Eagle();

		View getView() const override;

		double getResult(Race* race) override;
};