#define CATCH_CONFIG_MAIN
#include "../../1/Car/Car.h"
#include <catch2/catch.hpp>

TEST_CASE("Car constructor")
{
	CCar car;

	CHECK(car.GetTurnEngine() == false);
	CHECK(car.GetDirection() == "STAY");
	CHECK(car.GetGear() == "NEUTRAL");
	CHECK(car.GetSpeed() == 0);
}

TEST_CASE("Car TurnOnEngine")
{
	CCar car;
	car.TurnOnEngine();
	CHECK(car.GetTurnEngine() == true);

	CHECK(car.GetDirection() == "STAY");
	CHECK(car.GetGear() == "NEUTRAL");
	CHECK(car.GetSpeed() == 0);
}

TEST_CASE("Car TurnOffEngine")
{
	CCar car;
	CHECK(car.TurnOffEngine() == false);

	CHECK(car.GetTurnEngine() == false);
	CHECK(car.GetDirection() == "STAY");
	CHECK(car.GetGear() == "NEUTRAL");
	CHECK(car.GetSpeed() == 0);

	car.TurnOnEngine();
	CHECK(car.GetTurnEngine() == true);

	CHECK(car.SetGear(1));
	CHECK(car.TurnOffEngine() == false);
	CHECK(car.GetGear() == "FIRST");

	CHECK(car.SetSpeed(15) == true);
	CHECK(car.TurnOffEngine() == false);
	CHECK(car.GetSpeed() == 15);

	CHECK(car.SetGear(0));
	CHECK(car.TurnOffEngine() == false);
	CHECK(car.GetSpeed() == 15);
	CHECK(car.GetGear() == "NEUTRAL");

	CHECK(car.SetSpeed(0) == true);
	CHECK(car.TurnOffEngine() == true);
	CHECK(car.GetSpeed() == 0);
	CHECK(car.GetGear() == "NEUTRAL");

	CHECK(car.GetTurnEngine() == false);
}

TEST_CASE("Car SetGear, Engine = false")
{
	CCar car;

	CHECK(car.SetGear(0) == true);
	CHECK(car.SetGear(1) == false);

	CHECK(car.GetTurnEngine() == false);
	CHECK(car.GetDirection() == "STAY");
	CHECK(car.GetGear() == "NEUTRAL");
	CHECK(car.GetSpeed() == 0);
}

TEST_CASE("Car SetSpeed, Engine = false")
{
	CCar car;

	CHECK(car.SetSpeed(0) == true);
	CHECK(car.SetSpeed(1) == false);

	CHECK(car.GetTurnEngine() == false);
	CHECK(car.GetDirection() == "STAY");
	CHECK(car.GetGear() == "NEUTRAL");
	CHECK(car.GetSpeed() == 0);
}

TEST_CASE("Car SetGear, SetSpeed REVERSE->NEUTRAL->FIRST")
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

TEST_CASE("Car SetGear, SetSpeed REVERSE")
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

TEST_CASE("Car SetGear, SetSpeed FIRST")
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

TEST_CASE("Car SetGear, SetSpeed SECOND")
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

TEST_CASE("Car SetGear, SetSpeed THIRD")
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

TEST_CASE("Car SetGear, SetSpeed FOURTH")
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

TEST_CASE("Car SetGear, SetSpeed FIFTH")
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
