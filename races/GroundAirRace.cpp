#include "GroundAirRace.hpp"

#include "groundVehicles/BootsATV.hpp"
#include "groundVehicles/Camel.hpp"
#include "groundVehicles/CamelFast.hpp"
#include "groundVehicles/Centaur.hpp"

#include "airVehicles/Broom.hpp"
#include "airVehicles/Eagle.hpp"
#include "airVehicles/MagicCarpet.hpp"

GroundAirRace::GroundAirRace()
{
	registeredVehicles = new Vehicle*[7];
}

GroundAirRace::~GroundAirRace()
{
	for(size_t vehicle{}; vehicle < countRegisteredVehicles; ++vehicle)
	{
		delete registeredVehicles[vehicle];
	}
	delete[] registeredVehicles;
}

Race::View GroundAirRace::getView() const
{
	return GroundAir;
}

void GroundAirRace::registVehicle(Vehicle::View view)
{
	switch (view)
	{
		case Vehicle::BootsATV:    registeredVehicles[countRegisteredVehicles] = new BootsATV{};    break;
		case Vehicle::Broom:       registeredVehicles[countRegisteredVehicles] = new Broom{};       break;
		case Vehicle::Camel:       registeredVehicles[countRegisteredVehicles] = new Camel{};       break;
		case Vehicle::Centaur:     registeredVehicles[countRegisteredVehicles] = new Centaur{};     break;
		case Vehicle::Eagle:       registeredVehicles[countRegisteredVehicles] = new Eagle{};       break;
		case Vehicle::CamelFast:   registeredVehicles[countRegisteredVehicles] = new CamelFast{};   break;
		case Vehicle::MagicCarpet: registeredVehicles[countRegisteredVehicles] = new MagicCarpet{}; break;
	}
	++countRegisteredVehicles;
}

void GroundAirRace::startRace()
{
	Vehicle* temp{nullptr};
	for (size_t iVehicle{}; iVehicle < countRegisteredVehicles - 1; ++iVehicle)
	{
		for (size_t jVehicle{}; jVehicle < countRegisteredVehicles - iVehicle - 1; ++jVehicle)
		{
			if (registeredVehicles[jVehicle + 0]->getResult(this) > registeredVehicles[jVehicle + 1]->getResult(this))
			{
				temp = registeredVehicles[jVehicle + 0];
				registeredVehicles[jVehicle + 0] = registeredVehicles[jVehicle + 1];
				registeredVehicles[jVehicle + 1] = temp;
			}
		}
	}
}
