#include "pch.h"
#include "Car.h"

CCar::CCar()
{
	m_engine = false;
	m_direction = Direction::STAY;
	m_speed = 0;
	m_gear = Gear::NEUTRAL;
}

bool CCar::GetTurnEngine() const
{
	return m_engine;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

std::string CCar::GetGear() const
{
	switch (m_gear)
	{
	case Gear::REVERSE:
		return "REVERSE";
	case Gear::NEUTRAL:
		return "NEUTRAL";
	case Gear::FIRST:
		return "FIRST";
	case Gear::SECOND:
		return "SECOND";
	case Gear::THIRD:
		return "THIRD";
	case Gear::FOURTH:
		return "FOURTH";
	case Gear::FIFTH:
		return "FIFTH";
	default:
		return "Unknown gear";
	}
}

std::string CCar::GetDirection() const
{
	switch (m_direction)
	{
	case Direction::FORWARD:
		return "FORWARD";
	case Direction::BACK:
		return "BACK";
	case Direction::STAY:
		return "STAY";
	default:
		return "Unknown direction";
	}
}

bool CCar::TurnOnEngine()
{
	if (!m_engine)
	{
		m_engine = true;
		return true;
	}
	return false;
}

bool CCar::TurnOffEngine()
{
	if (m_engine && m_speed == 0 && m_gear == Gear::NEUTRAL && m_direction == Direction::STAY)
	{
		m_engine = false;
		return true;
	}
	return false;
}

bool CCar::SetGearCheck(int gear, GearOfSpeed gearOfSpeed, Direction direction)
{
	if (m_speed >= gearOfSpeed.m_minSpeed && m_speed <= gearOfSpeed.m_maxSpeed && m_direction == direction)
	{
		m_gear = Gear(gear);
		return true;
	}
	return false;
}

bool CCar::SetGear(int gear)
{
	if (!m_engine)
	{
		if (gear == 0)
		{
			m_gear = Gear::NEUTRAL;
			return true;
		}
		return false;
	}

	if (m_gear == Gear::REVERSE && gear == 1)
	{
		if (m_speed == 0)
		{
			m_gear = Gear::FIRST;
			return true;
		}
		return false;
	}

	if (m_gear == Gear::NEUTRAL && gear == 1 && m_speed == 0)
	{
		if (m_direction == Direction::STAY)
		{
			m_gear = Gear::FIRST;
			return true;
		}
		return false;
	}

	switch (gear)
	{
	case -1:
		return SetGearCheck(-1, SPEED_STAY, Direction::STAY);
	case 0:
		m_gear = Gear::NEUTRAL;
		return true;
	case 1:
		return SetGearCheck(1, FIRST_SPEED, Direction::FORWARD);
	case 2:
		return SetGearCheck(2, SECOND_SPEED, Direction::FORWARD);
	case 3:
		return SetGearCheck(3, THIRD_SPEED, Direction::FORWARD);
	case 4:
		return SetGearCheck(4, FOURTH_SPEED, Direction::FORWARD);
	case 5:
		return SetGearCheck(5, FIFTH_SPEED, Direction::FORWARD);
	default:
		return false;
	}
}

bool CCar::SetSpeedCheck(int speed, GearOfSpeed gearOfSpeed, Direction direction)
{
	if (speed >= gearOfSpeed.m_minSpeed && speed <= gearOfSpeed.m_maxSpeed)
	{
		m_speed = speed;
		m_direction = direction;
		return true;
	}
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (!m_engine)
	{
		if (speed == 0)
		{
			m_speed = speed;
			return true;
		}
		return false;
	}

	switch (m_gear)
	{
	case Gear::REVERSE:
		return SetSpeedCheck(speed, SPEED_STAY, Direction::STAY) || SetSpeedCheck(speed, REVERSE_SPEED_NOT_NULL, Direction::BACK);
	case Gear::NEUTRAL:

		if ((m_speed - speed) >= 0)
		{
			return SetSpeedCheck(speed, SPEED_STAY, Direction::STAY) || SetSpeedCheck(speed, NEUTRAL_SPEED_NOT_NULL, Direction::FORWARD);
		}
		else
		{
			return false;
		}

	case Gear::FIRST:
		return SetSpeedCheck(speed, SPEED_STAY, Direction::STAY) || SetSpeedCheck(speed, FIRST_SPEED_NOT_NULL, Direction::FORWARD);
	case Gear::SECOND:
		return SetSpeedCheck(speed, SECOND_SPEED, Direction::FORWARD);
	case Gear::THIRD:
		return SetSpeedCheck(speed, THIRD_SPEED, Direction::FORWARD);
	case Gear::FOURTH:
		return SetSpeedCheck(speed, FOURTH_SPEED, Direction::FORWARD);
	case Gear::FIFTH:
		return SetSpeedCheck(speed, FIFTH_SPEED, Direction::FORWARD);
	default:
		return false;
	}
}
