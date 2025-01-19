#include "AirRace.hpp"

#include "airVehicles/Broom.hpp"
#include "airVehicles/Eagle.hpp"
#include "airVehicles/MagicCarpet.hpp"

AirRace::AirRace()
{
	registeredVehicles = new Vehicle*[4];
}

AirRace::~AirRace()
{
	for(size_t vehicle{}; vehicle < countRegisteredVehicles; ++vehicle)
	{
		delete registeredVehicles[vehicle];
	}
	delete[] registeredVehicles;
}

Race::View AirRace::getView() const
{
	return Air;
}

void AirRace::registVehicle(Vehicle::View view)
{
	switch (view)
	{
		case Vehicle::Broom:       registeredVehicles[countRegisteredVehicles] = new Broom{};       break;
		case Vehicle::Eagle:       registeredVehicles[countRegisteredVehicles] = new Eagle{};       break;
		case Vehicle::MagicCarpet: registeredVehicles[countRegisteredVehicles] = new MagicCarpet{}; break;
	}
	++countRegisteredVehicles;
}

void AirRace::startRace()
{
	Vehicle* temp{nullptr};
	for (size_t iVehicle{}; iVehicle < countRegisteredVehicles - 1; ++iVehicle)
	{
		for (size_t jVehicle{}; jVehicle < countRegisteredVehicles - iVehicle - 1; ++jVehicle)
		{
			if (registeredVehicles[jVehicle + 0]->getResultRaceTime(this) > registeredVehicles[jVehicle + 1]->getResultRaceTime(this))
			{
				temp = registeredVehicles[jVehicle + 0];
				registeredVehicles[jVehicle + 0] = registeredVehicles[jVehicle + 1];
				registeredVehicles[jVehicle + 1] = temp;
			}
		}
	}
}
