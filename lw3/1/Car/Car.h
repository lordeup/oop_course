#pragma once
#include <string>

class CCar
{
public:
	CCar();

	std::string GetGear() const;
	std::string GetDirection() const;
	std::string GetEngine() const;
	int GetSpeed() const;
	bool GetTurnEngine() const;

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	enum class Gear
	{
		REVERSE = -1,
		NEUTRAL,
		FIRST,
		SECOND,
		THIRD,
		FOURTH,
		FIFTH
	};

	enum class Direction
	{
		FORWARD,
		BACK,
		STAY
	};

	struct GearOfSpeed
	{
		int m_minSpeed;
		int m_maxSpeed;
	};

	bool SetGearCheck(int gear, GearOfSpeed gearOfSpeed, Direction direction);
	bool SetSpeedCheck(int speed, GearOfSpeed gearOfSpeed, Direction direction);

	const GearOfSpeed SPEED_STAY = { 0, 0 };
	const GearOfSpeed REVERSE_SPEED_NOT_NULL = { 1, 20 };
	const GearOfSpeed FIRST_SPEED = { 0, 30 };
	const GearOfSpeed FIRST_SPEED_NOT_NULL = { 1, 30 };
	const GearOfSpeed SECOND_SPEED = { 20, 50 };
	const GearOfSpeed THIRD_SPEED = { 30, 60 };
	const GearOfSpeed FOURTH_SPEED = { 40, 90 };
	const GearOfSpeed FIFTH_SPEED = { 50, 150 };

	bool m_engine;
	Direction m_direction;
	int m_speed;
	Gear m_gear;
};
