#pragma once

class Race;

class Vehicle
{
	protected:
		int speed{};

		Vehicle(int initSpeed);

	public:
		enum Type
		{
			Ground = 1,
			Air = 2,
		};

		enum View
		{
			BootsATV = 1,
			Broom = 2,
			Camel = 3,
			Centaur = 4,
			Eagle = 5,
			CamelFast = 6,
			MagicCarpet = 7,
		};

		virtual View getView() const = 0;

		int getRaceTime(Race* race) const;

		virtual double getResultRaceTime(Race* race) = 0;
};
