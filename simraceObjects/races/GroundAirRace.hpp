#pragma once

#include "Race.hpp"

class GroundAirRace: public Race
{
	public:
		GroundAirRace();
		~GroundAirRace();

		View getView() const override;

		void registVehicle(Vehicle::View view) override;

		void startRace() override;
};
