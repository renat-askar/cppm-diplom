#pragma once

#include "Race.hpp"

class AirRace: public Race
{
	public:
		AirRace();
		~AirRace();

		View getView() const;

		void registVehicle(Vehicle::View view) override;

		void startRace() override;
};
