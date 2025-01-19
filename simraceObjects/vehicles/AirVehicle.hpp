#pragma once

#include "Vehicle.hpp"

class AirVehicle: public Vehicle
{
	public:
		AirVehicle(int initSpeed);

		Type getType() const;

		View getView() const = 0;

		virtual double getResultRaceTime(Race* race) = 0;
};
