#define CATCH_CONFIG_MAIN
#include "../../1/Car/Car.h"
#include "../../1/Car/CarCommunication.h"
#include "../../1/Car/Const.h"
#include <catch2/catch.hpp>

TEST_CASE("Car")
{
	SECTION("Car constructor")
	{
		CCar car;

		CHECK(car.GetTurnEngine() == false);
		CHECK(car.GetDirection() == "STAY");
		CHECK(car.GetGear() == "NEUTRAL");
		CHECK(car.GetSpeed() == 0);
	}

	SECTION("Car TurnOnEngine")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.GetTurnEngine() == true);

		CHECK(car.GetDirection() == "STAY");
		CHECK(car.GetGear() == "NEUTRAL");
		CHECK(car.GetSpeed() == 0);

		CHECK(car.SetGear(1) == true);
		CHECK(car.SetGear(1) == true);
	}

	SECTION("Car TurnOffEngine")
	{
		CCar car;
		CHECK(car.TurnOffEngine() == false);

		CHECK(car.GetTurnEngine() == false);
		CHECK(car.GetDirection() == "STAY");
		CHECK(car.GetGear() == "NEUTRAL");
		CHECK(car.GetSpeed() == 0);

		car.TurnOnEngine();
		CHECK(car.GetTurnEngine() == true);

		CHECK(car.SetGear(1) == true);
		CHECK(car.TurnOffEngine() == false);
		CHECK(car.GetGear() == "FIRST");

		CHECK(car.SetSpeed(15) == true);
		CHECK(car.TurnOffEngine() == false);
		CHECK(car.GetSpeed() == 15);

		CHECK(car.SetGear(0) == true);
		CHECK(car.TurnOffEngine() == false);
		CHECK(car.GetSpeed() == 15);
		CHECK(car.GetGear() == "NEUTRAL");

		CHECK(car.SetSpeed(0) == true);
		CHECK(car.TurnOffEngine() == true);
		CHECK(car.GetSpeed() == 0);
		CHECK(car.GetGear() == "NEUTRAL");

		CHECK(car.GetTurnEngine() == false);
	}

	SECTION("Car SetGear, Engine = false")
	{
		CCar car;

		CHECK(car.SetGear(0) == true);
		CHECK(car.SetGear(1) == false);

		CHECK(car.GetTurnEngine() == false);
		CHECK(car.GetDirection() == "STAY");
		CHECK(car.GetGear() == "NEUTRAL");
		CHECK(car.GetSpeed() == 0);
	}

	SECTION("Car SetSpeed, Engine = false")
	{
		CCar car;

		CHECK(car.SetSpeed(0) == true);
		CHECK(car.SetSpeed(1) == false);

		CHECK(car.GetTurnEngine() == false);
		CHECK(car.GetDirection() == "STAY");
		CHECK(car.GetGear() == "NEUTRAL");
		CHECK(car.GetSpeed() == 0);
	}

	SECTION("Car SetGear, SetSpeed REVERSE->NEUTRAL->FIRST")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.GetTurnEngine() == true);

		CHECK(car.SetGear(-1) == true);
		CHECK(car.SetSpeed(10) == true);
		CHECK(car.SetGear(0) == true);

		CHECK(car.SetGear(1) == false);
		CHECK(car.SetSpeed(0) == true);

		CHECK(car.GetDirection() == "STAY");
		CHECK(car.SetGear(1) == true);
	}

	SECTION("Car SetGear, SetSpeed REVERSE")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.GetTurnEngine() == true);

		CHECK(car.GetSpeed() == 0);
		CHECK(car.SetGear(-1) == true);

		CHECK(car.SetSpeed(20) == true);
		CHECK(car.SetSpeed(21) == false);

		CHECK(car.GetDirection() == "BACK");
		CHECK(car.GetGear() == "REVERSE");
		CHECK(car.GetSpeed() == 20);

		CHECK(car.SetGear(-2) == false);

		CHECK(car.SetGear(1) == false);
		CHECK(car.SetSpeed(0) == true);
		CHECK(car.SetGear(1) == true);
	}

	SECTION("Car SetGear, SetSpeed NEUTRAL")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.GetTurnEngine() == true);

		CHECK(car.SetSpeed(15) == false);
		CHECK(car.SetSpeed(0) == true);
	}

	SECTION("Car SetGear, SetSpeed FIRST")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.GetTurnEngine() == true);

		CHECK(car.SetGear(1) == true);
		CHECK(car.SetSpeed(10) == true);

		CHECK(car.SetSpeed(30) == true);
		CHECK(car.SetSpeed(31) == false);

		CHECK(car.GetDirection() == "FORWARD");
		CHECK(car.GetGear() == "FIRST");
		CHECK(car.GetSpeed() == 30);
	}

	SECTION("Car SetGear, SetSpeed SECOND")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.GetTurnEngine() == true);

		CHECK(car.SetGear(1) == true);
		CHECK(car.SetSpeed(19) == true);

		CHECK(car.GetDirection() == "FORWARD");
		CHECK(car.GetGear() == "FIRST");
		CHECK(car.GetSpeed() == 19);

		CHECK(car.SetGear(2) == false);
		CHECK(car.SetSpeed(20) == true);
		CHECK(car.SetGear(2) == true);

		CHECK(car.GetDirection() == "FORWARD");
		CHECK(car.GetGear() == "SECOND");
		CHECK(car.GetSpeed() == 20);

		CHECK(car.SetSpeed(50) == true);
		CHECK(car.SetSpeed(51) == false);
		CHECK(car.GetSpeed() == 50);
	}

	SECTION("Car SetGear, SetSpeed THIRD")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.GetTurnEngine() == true);

		CHECK(car.SetGear(1) == true);
		CHECK(car.SetSpeed(29) == true);

		CHECK(car.GetDirection() == "FORWARD");
		CHECK(car.GetGear() == "FIRST");
		CHECK(car.GetSpeed() == 29);

		CHECK(car.SetGear(3) == false);
		CHECK(car.SetSpeed(30) == true);
		CHECK(car.SetGear(3) == true);

		CHECK(car.GetDirection() == "FORWARD");
		CHECK(car.GetGear() == "THIRD");
		CHECK(car.GetSpeed() == 30);

		CHECK(car.SetSpeed(60) == true);
		CHECK(car.SetSpeed(61) == false);
		CHECK(car.GetSpeed() == 60);
	}

	SECTION("Car SetGear, SetSpeed FOURTH")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.GetTurnEngine() == true);

		CHECK(car.SetGear(1) == true);
		CHECK(car.SetSpeed(30) == true);
		CHECK(car.SetGear(2) == true);
		CHECK(car.SetSpeed(39) == true);

		CHECK(car.GetDirection() == "FORWARD");
		CHECK(car.GetGear() == "SECOND");
		CHECK(car.GetSpeed() == 39);

		CHECK(car.SetGear(4) == false);
		CHECK(car.SetSpeed(40) == true);
		CHECK(car.SetGear(4) == true);

		CHECK(car.GetDirection() == "FORWARD");
		CHECK(car.GetGear() == "FOURTH");
		CHECK(car.GetSpeed() == 40);

		CHECK(car.SetSpeed(90) == true);
		CHECK(car.SetSpeed(91) == false);
		CHECK(car.GetSpeed() == 90);
	}

	SECTION("Car SetGear, SetSpeed FIFTH")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.GetTurnEngine() == true);

		CHECK(car.SetGear(1) == true);
		CHECK(car.SetSpeed(30) == true);
		CHECK(car.SetGear(2) == true);
		CHECK(car.SetSpeed(49) == true);

		CHECK(car.GetDirection() == "FORWARD");
		CHECK(car.GetGear() == "SECOND");
		CHECK(car.GetSpeed() == 49);

		CHECK(car.SetGear(5) == false);
		CHECK(car.SetSpeed(50) == true);
		CHECK(car.SetGear(5) == true);

		CHECK(car.GetDirection() == "FORWARD");
		CHECK(car.GetGear() == "FIFTH");
		CHECK(car.GetSpeed() == 50);

		CHECK(car.SetSpeed(150) == true);
		CHECK(car.SetSpeed(151) == false);
		CHECK(car.GetSpeed() == 150);

		CHECK(car.SetGear(6) == false);
	}
}

TEST_CASE("CarCommunication")
{
	SECTION("INFO_MODE")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(-1);
		car.SetSpeed(10);
		std::stringstream issIn(INFO_MODE);
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "Engine condition ON\nDirection of movement BACK\nSpeed 10\nGear REVERSE\n\n");
	}

	SECTION("ENGINE_ON_MODE")
	{
		CCar car;
		std::stringstream issIn(ENGINE_ON_MODE);
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "The engine is on\n\n");
	}

	SECTION("ERROR_ENGINE_ON")
	{
		CCar car;
		car.TurnOnEngine();
		std::stringstream issIn(ENGINE_ON_MODE);
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "Engine failed to turn on\n\n");
	}

	SECTION("ENGINE_OFF_MODE")
	{
		CCar car;
		car.TurnOnEngine();
		std::stringstream issIn(ENGINE_OFF_MODE);
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "The engine is off\n\n");
	}

	SECTION("ERROR_ENGINE_OFF")
	{
		CCar car;
		std::stringstream issIn(ENGINE_OFF_MODE);
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "Engine failed to turn off\nThe engine can be turned off, if the speed is 0, the transmission is neutral in the direction of standing\n\n");
	}

	SECTION("SET_GEAR_MODE Error non number")
	{
		CCar car;
		std::stringstream issIn("SetGear hello");
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "You entered not a number\n\n");
	}

	SECTION("SET_GEAR_MODE Error outside1")
	{
		CCar car;
		std::stringstream issIn("SetGear -2");
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "Gear must be a number from -1 to 5\n\n");
	}

	SECTION("SET_GEAR_MODE Error outside2")
	{
		CCar car;
		std::stringstream issIn("SetGear 6");
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "Gear must be a number from -1 to 5\n\n");
	}

	SECTION("SET_GEAR_MODE set gear")
	{
		CCar car;
		car.TurnOnEngine();
		std::stringstream issIn("SetGear -1");
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "Gear is set to -1\n\n");
	}

	SECTION("SET_GEAR_MODE not set gear")
	{
		CCar car;
		std::stringstream issIn("SetGear -1");
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "Gear is not set\n\n");
	}

	SECTION("SET_SPEED_MODE Error non number")
	{
		CCar car;
		std::stringstream issIn("SetSpeed hello");
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "You entered not a number\n\n");
	}

	SECTION("SET_SPEED_MODE Error outside1")
	{
		CCar car;
		std::stringstream issIn("SetSpeed -1");
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "The speed should be a number from 0 to 150\n\n");
	}

	SECTION("SET_SPEED_MODE Error outside2")
	{
		CCar car;
		std::stringstream issIn("SetSpeed 151");
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "The speed should be a number from 0 to 150\n\n");
	}

	SECTION("SET_SPEED_MODE set speed")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(-1);
		std::stringstream issIn("SetSpeed 10");
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "The speed is set to 10\n\n");
	}

	SECTION("SET_SPEED_MODE not set speed")
	{
		CCar car;
		std::stringstream issIn("SetSpeed 10");
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "The speed is not set\n\n");
	}

	SECTION("UNKNOWN_MODE")
	{
		CCar car;
		std::stringstream issIn("hello");
		std::stringstream issOut;
		CCarCommunication carCommunication(issIn, issOut, car);

		carCommunication.ProcessingCommand();
		CHECK(issOut.str() == "Unknown mode\n\n");
	}
}
