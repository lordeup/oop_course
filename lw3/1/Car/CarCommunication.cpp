#include "pch.h"
#include "Car.h"
#include "CarCommunication.h"
#include "Const.h"

CCarCommunication::CCarCommunication(std::istream& input, std::ostream& output, CCar& car)
	: m_input(input)
	, m_output(output)
	, m_car(car)
{
}

void CCarCommunication::PrintInfo(CCar& car)
{
	m_output << ENGINE_CONDITION_INFO << car.GetEngine() << std::endl;
	m_output << DIRECTION_INFO << car.GetDirection() << std::endl;
	m_output << SPEED_INFO << car.GetSpeed() << std::endl;
	m_output << GEAR_INFO << car.GetGear() << std::endl;
}

bool CCarCommunication::CheckForNumber(int& number)
{
	try
	{
		std::string str;
		m_input >> str;
		number = std::stoi(str);
		return true;
	}
	catch (const std::invalid_argument&)
	{
		return false;
	}
}

void CCarCommunication::SetGearMode(CCar& car)
{
	int number;

	if (!CheckForNumber(number))
	{
		m_output << ERROR_NON_NUMBER;
	}
	else if (number < GEAR_REVERSE || number > GEAR_FIFTH)
	{
		m_output << ERROR_SET_GEAR_NUMBER_OUTSIDE;
	}
	else
	{
		if (car.SetGear(number))
		{
			m_output << SET_GEAR << number << std::endl;
		}
		else
		{
			m_output << ERROR_SET_GEAR;
		}
	}
}

void CCarCommunication::SetSpeedMode(CCar& car)
{
	int number;

	if (!CheckForNumber(number))
	{
		m_output << ERROR_NON_NUMBER;
	}
	else if (number < SPEED_MIN || number > SPEED_MAX)
	{
		m_output << ERROR_SET_SPEED_NUMBER_OUTSIDE;
	}
	else
	{
		if (car.SetSpeed(number))
		{
			m_output << SET_SPEED << number << std::endl;
		}
		else
		{
			m_output << ERROR_SET_SPEED;
		}
	}
}

void CCarCommunication::ProcessingCommand()
{
	std::string str;

	while (m_input >> str)
	{
		if (str == INFO_MODE)
		{
			PrintInfo(m_car);
		}
		else if (str == ENGINE_ON_MODE)
		{
			m_output << (m_car.TurnOnEngine() ? ENGINE_ON : ERROR_ENGINE_ON);
		}
		else if (str == ENGINE_OFF_MODE)
		{
			m_output << (m_car.TurnOffEngine() ? ENGINE_OFF : ERROR_ENGINE_OFF);
		}
		else if (str == SET_GEAR_MODE)
		{
			SetGearMode(m_car);
		}
		else if (str == SET_SPEED_MODE)
		{
			SetSpeedMode(m_car);
		}
		else
		{
			m_output << UNKNOWN_MODE;
		}

		m_output << std::endl;
	}
}
