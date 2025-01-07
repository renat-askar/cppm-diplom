#pragma once

#include "Vehicle.hpp"

class GroundVehicle: public Vehicle
{
	protected:
		int drivingTimeBeforeRest{};
		double restDuration{};

	public:
		GroundVehicle(int setSpeed, int setDrivingTimeBeforeRest, double setRestDuration);

		Type getType() const;

		View getView() const = 0;

		void setRestDuration(double setRestDuration);

		double getTime(Race* race) const;

		int getCountOfRest(Race* race) const;

		virtual double getResult(Race* race) = 0;
};
