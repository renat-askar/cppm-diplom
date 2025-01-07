#pragma once

#include "Vehicle.hpp"

class Race
{
	protected:
		int distance{};

		Vehicle** registeredVehicles{nullptr};
		size_t countRegisteredVehicles{};

	public:
		enum View
		{
			Ground = 1,
			Air = 2,
			GroundAir = 3,
		};

		virtual View getView() const = 0;

		void setDistance(int distance);
		int getDistance() const;

		Vehicle* getVehicleAt(size_t index) const;

		size_t getCountRegisteredVehicles() const;

		virtual void registVehicle(Vehicle::View view) = 0;

		virtual void startRace() = 0;
};
