#include <iostream>

#include "Windows.h"

#include "Race.hpp"
#include "GroundRace.hpp"
#include "AirRace.hpp"
#include "GroundAirRace.hpp"

#include "Vehicle.hpp"
#include "GroundVehicle.hpp"
#include "AirVehicle.hpp"

void clearIgnoreLine()
{
	std::cin.clear();
	#pragma push_macro("max")
		#undef max
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	#pragma pop_macro("max")
}

void clearConsole(){std::cout << "\033c";}

bool hasUnextractedInput()
{
	return !std::cin.eof() && std::cin.peek() != '\n';
}

void printRaceViewInputMenuText()
{
	std::cout << "1. ����� ��� ��������� ����������\n"
		"2. ����� ��� ���������� ����������\n"
		"3. ����� ��� ��������� � ���������� ����������\n"
		"�������� ��� �����: ";
}

int getRaceViewInput()
{
	int raceViewSelect{};
	do
	{
		printRaceViewInputMenuText();
		std::cin >> raceViewSelect;
		if (!std::cin || hasUnextractedInput() || raceViewSelect < 1 || raceViewSelect > 3)
		{
			clearIgnoreLine();
			clearConsole();
		} else break;
	} while(true);
	return raceViewSelect;
}

int getRaceDistance()
{
	int inputDistance{};
	do
	{
		clearConsole();
		std::cout << "������� ����� ��������� (������ ���� ������������): ";
		std::cin >> inputDistance;
		if(!std::cin || hasUnextractedInput() || inputDistance <= 0)
		{
			clearIgnoreLine();
		} else break;
	} while(true);
	return inputDistance;
}

int getRegisterMenuInput(Race* race)
{
	int raceRegisterSelectMenuInput{};
	do
	{
		clearConsole();
		if (race->getCountRegisteredVehicles() < 2)
			std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������\n";

		std::cout << "1. ���������������� ���������\n";

		if (race->getCountRegisteredVehicles() >= 2)
			std::cout << "2. ������ �����\n";

		std::cout << "�������� ��������: ";

		std::cin >> raceRegisterSelectMenuInput;
		if (!std::cin || hasUnextractedInput() || raceRegisterSelectMenuInput < 1 || raceRegisterSelectMenuInput > 2)
		{
			clearIgnoreLine();
		} else break;
	} while(true);

	return raceRegisterSelectMenuInput;
}

const char* getRaceViewStr(Race* race)
{
	switch(race->getView())
	{
		case Race::Ground:    return "���������";
		case Race::Air:       return "����������";
		case Race::GroundAir: return "��������� � ����������";
		default: return "";
	}
}

const char* getVehicleViewStr(Vehicle::View view)
{
	switch(view)
	{
		case Vehicle::BootsATV:    return "�������-���������";
		case Vehicle::Broom:       return "�����";
		case Vehicle::Camel:       return "�������";
		case Vehicle::Centaur:     return "�������";
		case Vehicle::Eagle:       return "���";
		case Vehicle::CamelFast:   return "�������-���������";
		case Vehicle::MagicCarpet: return "����-������";
		default: return "";
	}
}

Vehicle::Type getVehicleTypeFromView(Vehicle::View view)
{
	switch(view)
	{
		case Vehicle::BootsATV:    return Vehicle::Ground;
		case Vehicle::Broom:       return Vehicle::Air;
		case Vehicle::Camel:       return Vehicle::Ground;
		case Vehicle::Centaur:     return Vehicle::Ground;
		case Vehicle::Eagle:       return Vehicle::Air;
		case Vehicle::CamelFast:   return Vehicle::Ground;
		case Vehicle::MagicCarpet: return Vehicle::Air;
		default: return Vehicle::Ground;
	}
}

bool raceContainRegisteredVehicle(Race* race, Vehicle::View view)
{
	for(size_t vehicle{}; vehicle < race->getCountRegisteredVehicles(); ++vehicle)
	{
		if(race->getVehicleAt(vehicle)->getView() == view)
			return true;
	}
	return false;
}

void registryVehicle(Race* race, Vehicle::View view)
{
	clearConsole();
	if(raceContainRegisteredVehicle(race, view))
	{
		std::cout << getVehicleViewStr(view) << " ��� ���������������!\n";
	}
	else if(race->getView() != getVehicleTypeFromView(view) && race->getView() != Race::GroundAir)
	{
		std::cout << "������� ���������������� ������������ ��� ������������� ��������!\n";
	}
	else
	{
		race->registVehicle(view);
		std::cout << getVehicleViewStr(view) << " ������� ���������������!\n";
	}
}

void printRegisteredVehicles(Race* race)
{
	if(race->getCountRegisteredVehicles() == 0) return;
	std::cout << getVehicleViewStr(race->getVehicleAt(0)->getView());
	for (size_t vehicle{1}; vehicle < race->getCountRegisteredVehicles(); ++vehicle)
	{
		std::cout << ", " << getVehicleViewStr(race->getVehicleAt(vehicle)->getView());
	}
}

void printVehicleRegisterInputMenuText(Race* race)
{
	std::cout << "����� ��� " << getRaceViewStr(race) << " ����������. ����������: " << race->getDistance() << '\n'
		<< "������������������ ������������ ��������: ";
	printRegisteredVehicles(race);
	std::cout << '\n' <<
		"1. �������-���������\n"
		"2. �����\n"
		"3. �������\n"
		"4. �������\n"
		"5. ���\n"
		"6. �������-���������\n"
		"7. ����-������\n"
		"0. ��������� �����������\n"
		"�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
}

int getVehilceRegisterMenu(Race* race)
{
	int vehicleRegistSelect{};
	do
	{
		printVehicleRegisterInputMenuText(race);
		std::cin >> vehicleRegistSelect;
		if (!std::cin || hasUnextractedInput() || vehicleRegistSelect < 0 || vehicleRegistSelect > 7)
		{
			clearIgnoreLine();
			clearConsole();
		} else break;
	} while(true);
	return vehicleRegistSelect;
}

void registerVehicleSwitcher(Race* race, bool& raceRegistryActive)
{
	switch (getVehilceRegisterMenu(race))
	{
		case Vehicle::BootsATV:    registryVehicle(race, Vehicle::BootsATV);    break;
		case Vehicle::Broom:       registryVehicle(race, Vehicle::Broom);       break;
		case Vehicle::Camel:       registryVehicle(race, Vehicle::Camel);       break;
		case Vehicle::Centaur:     registryVehicle(race, Vehicle::Centaur);     break;
		case Vehicle::Eagle:       registryVehicle(race, Vehicle::Eagle);       break;
		case Vehicle::CamelFast:   registryVehicle(race, Vehicle::CamelFast);   break;
		case Vehicle::MagicCarpet: registryVehicle(race, Vehicle::MagicCarpet); break;
		case 0: raceRegistryActive = false; break;
	}
}

void raceRegisterMenu(Race* race)
{
	bool raceRegistryActive{true};
	clearConsole();
	do
	{
		registerVehicleSwitcher(race, raceRegistryActive);
	}
	while(raceRegistryActive);
}

void raceMenuSwitcher(Race* race, bool& raceNotStarted)
{
	switch(getRegisterMenuInput(race))
	{
		case 1: raceRegisterMenu(race); break;
		case 2:
		{
			if (race->getCountRegisteredVehicles() < 2)
				break;
			raceNotStarted = false; break;
		}
	}
}

void printRaceResultsText(Race* race)
{
	clearConsole();
	std::cout << "���������� �����: \n";
	for(size_t vehicle{}; vehicle < race->getCountRegisteredVehicles(); ++vehicle)
	{
		std::cout << vehicle + 1 << ". " << getVehicleViewStr(race->getVehicleAt(vehicle)->getView()) << ". �����: " << race->getVehicleAt(vehicle)->getResultRaceTime(race) << '\n';
	}
	std::cout << '\n';
}

void printRaceResultsInputMenuText(Race* race)
{
	printRaceResultsText(race);
	std::cout << "1. �������� ��� ���� �����\n"
		"2. �����\n"
		"�������� ��������: ";
}

void setSimraceProcess(Race* race, bool& simraceProcessMenu)
{
	int raceResultsMenuSelectInput{};
	do
	{
		printRaceResultsInputMenuText(race);
		std::cin >> raceResultsMenuSelectInput;
		if (!std::cin || hasUnextractedInput() || raceResultsMenuSelectInput < 1 || raceResultsMenuSelectInput > 2)
		{
			clearIgnoreLine();
			clearConsole();
		} else break;
	} while(true);

	switch(raceResultsMenuSelectInput)
	{
		case 1: clearConsole(); return;
		case 2: simraceProcessMenu = false;
	}
}

void simRace(Race* race, bool& simraceProcessMenu)
{
	race->setDistance(getRaceDistance());
	bool raceNotStarted{true};
	while(raceNotStarted)
	{
		raceMenuSwitcher(race, raceNotStarted);
	}

	race->startRace();
	setSimraceProcess(race, simraceProcessMenu);
}

struct RaceViews
{
	GroundRace groundRace{};
	AirRace airRace{};
	GroundAirRace groundAirRace{};
};

Race* raceViewSwitcher(Race* race, RaceViews& raceViews)
{
	switch(getRaceViewInput())
	{
		case 1:	return &(raceViews.groundRace);
		case 2: return &(raceViews.airRace);
		case 3: return &(raceViews.groundAirRace);
		default: return race;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "����� ���������� � �������� ���������!\n";

	bool simraceProcess{true};
	while(simraceProcess)
	{
		{
			Race* race{nullptr};
			RaceViews raceViews{};
			race = raceViewSwitcher(race, raceViews);
			simRace(race, simraceProcess);
		}
	}
	clearConsole();
	return 0;
}
