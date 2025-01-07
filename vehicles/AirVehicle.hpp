#pragma once

#include "Vehicle.hpp"

class AirVehicle: public Vehicle
{
	public:
		AirVehicle(int setSpeed);

		Type getType() const;

		View getView() const = 0;

		virtual double getResult(Race* race) = 0;
};
