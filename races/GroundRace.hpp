#pragma once

#include "Race.hpp"

class GroundRace: public Race
{
	public:
		GroundRace();
		~GroundRace();

		View getView() const override;

		void registVehicle(Vehicle::View view) override;

		void startRace() override;
};
