#include "GroundRace.hpp"

#include "groundVehicles/BootsATV.hpp"
#include "groundVehicles/Camel.hpp"
#include "groundVehicles/CamelFast.hpp"
#include "groundVehicles/Centaur.hpp"

GroundRace::GroundRace()
{
	registeredVehicles = new Vehicle*[4];
}

GroundRace::~GroundRace()
{
	for(size_t vehicle{}; vehicle < countRegisteredVehicles; ++vehicle)
	{
		delete registeredVehicles[vehicle];
	}
	delete[] registeredVehicles;
}

Race::View GroundRace::getView() const
{
	return Ground;
}

void GroundRace::registVehicle(Vehicle::View view)
{
	switch(view)
	{
		case Vehicle::BootsATV:  registeredVehicles[countRegisteredVehicles] = new BootsATV{};  break;
		case Vehicle::Camel:     registeredVehicles[countRegisteredVehicles] = new Camel{};     break;
		case Vehicle::Centaur:   registeredVehicles[countRegisteredVehicles] = new Centaur{};   break;
		case Vehicle::CamelFast: registeredVehicles[countRegisteredVehicles] = new CamelFast{}; break;
	}
	++countRegisteredVehicles;
}

void GroundRace::startRace()
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
