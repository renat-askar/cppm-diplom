#pragma once

#include "AirVehicle.hpp"

class MagicCarpet: public AirVehicle
{
	public:
		MagicCarpet();

		View getView() const override;

		double getResult(Race* race) override;
};
