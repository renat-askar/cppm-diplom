#pragma once

#include "Vehicle.hpp"

class GroundVehicle: public Vehicle
{
	protected:
		int drivingTimeBeforeRest{};
		double restDuration{};

	public:
		GroundVehicle(int initSpeed, int initDrivingTimeBeforeRest, double initRestDuration);

		Type getType() const;

		View getView() const = 0;

		void setRestDuration(double restDuration);

		double getRaceTime(Race* race) const;

		int getCountOfRest(Race* race) const;

		virtual double getResultRaceTime(Race* race) = 0;
};
