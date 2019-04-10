#include "pch.h"
#include "Car.h"
#include "Const.h"
#include <iostream>

void PrintInfo(CCar& car)
{
	std::cout << ENGINE_CONDITION_INFO << car.GetTurnEngine() << std::endl;
	std::cout << DIRECTION_INFO << car.GetDirection() << std::endl;
	std::cout << SPEED_INFO << car.GetSpeed() << std::endl;
	std::cout << GEAR_INFO << car.GetGear() << std::endl;
}

bool CheckForNumber(int& number)
{
	try
	{
		std::string str;
		std::cin >> str;
		number = std::stoi(str);
		return true;
	}
	catch (const std::invalid_argument&)
	{
		return false;
	}
}

void SetGearMode(CCar& car)
{
	int number;

	if (!CheckForNumber(number))
	{
		std::cout << ERROR_NON_NUMBER << std::endl;
	}
	else if (number < -1 || number > 5)
	{
		std::cout << ERROR_SET_GEAR_NUMBER_OUTSIDE << std::endl;
	}
	else
	{
		if (car.SetGear(number))
		{
			std::cout << SET_GEAR << number << std::endl;
		}
		else
		{
			std::cout << ERROR_SET_GEAR << std::endl;
		}
	}
}

void SetSpeedMode(CCar& car)
{
	int number;

	if (!CheckForNumber(number))
	{
		std::cout << ERROR_NON_NUMBER << std::endl;
	}

	else if (number < 0 || number > 150)
	{
		std::cout << ERROR_SET_SPEED_NUMBER_OUTSIDE << std::endl;
	}
	else
	{
		if (car.SetSpeed(number))
		{
			std::cout << SET_SPEED << number << std::endl;
		}
		else
		{
			std::cout << ERROR_SET_SPEED << std::endl;
		}
	}
}

int main()
{
	CCar car;

	std::string str;

	while (std::cin >> str)
	{
		if (str == INFO_MODE)
		{
			PrintInfo(car);
		}
		else if (str == ENGINE_ON_MODE)
		{
			std::cout << (car.TurnOnEngine() ? ENGINE_ON : ERROR_ENGINE_ON);
		}
		else if (str == ENGINE_OFF_MODE)
		{
			std::cout << (car.TurnOffEngine() ? ENGINE_OFF : ERROR_ENGINE_OFF);
		}
		else if (str == SET_GEAR_MODE)
		{
			SetGearMode(car);
		}
		else if (str == SET_SPEED_MODE)
		{
			SetSpeedMode(car);
		}
		else
		{
			std::cout << UNKNOWN_MODE;
		}

		std::cout << std::endl;
	}

	return 0;
}
