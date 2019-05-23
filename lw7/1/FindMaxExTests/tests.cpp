#define CATCH_CONFIG_MAIN
#include "../../1/FindMaxEx/FindMax.h"
#include "../../1/FindMaxExTests/Sportsman.h"
#include <catch2/catch.hpp>

bool ComparisonIntNumberMin(const int& a, const int& b)
{
	return a > b;
}

bool ComparisonIntNumberMax(const int& a, const int& b)
{
	return a < b;
}

TEST_CASE("int")
{
	SECTION("find min")
	{
		int minNumber{};
		std::vector<int> numberVector{ 15, 18, 96, -12, -100, 67, 125 };
		CHECK(FindMax(numberVector, minNumber, ComparisonIntNumberMin) == true);
		CHECK(minNumber == -100);
	}

	SECTION("find max")
	{
		int maxNumber{};
		std::vector<int> numberVector{ 15, 18, 96, -12, -100, 67, 125 };
		CHECK(FindMax(numberVector, maxNumber, ComparisonIntNumberMax) == true);
		CHECK(maxNumber == 125);
	}
}

TEST_CASE("Sportsman")
{
	Sportsman sportsman1{ "Nathan Jack Floyd", 179.2, 78.1 };
	Sportsman sportsman2{ "David John Haynes", 170.6, 85.5 };
	Sportsman sportsman3{ "Richard Maximilian Sherman", 192.1, 90.7 };
	Sportsman sportsman4{ "Roger Logan Carroll", 186.6, 65.4 };
	Sportsman sportsman5{ "Peter John Richardson", 190.6, 102.0 };

	std::vector<Sportsman> sportsmanVector{ sportsman1, sportsman2, sportsman3, sportsman4, sportsman5 };

	SECTION("FindMax height")
	{
		Sportsman sportsmanMaxHeight;
		CHECK(FindMax(sportsmanVector, sportsmanMaxHeight, ComparisonHeight) == true);
		CHECK(sportsmanMaxHeight.name == sportsman3.name);
		CHECK(sportsmanMaxHeight.height == sportsman3.height);
		CHECK(sportsmanMaxHeight.weight == sportsman3.weight);
	}

	SECTION("FindMax weight")
	{
		Sportsman sportsmanMaxWeight;
		CHECK(FindMax(sportsmanVector, sportsmanMaxWeight, ComparisonWeight) == true);
		CHECK(sportsmanMaxWeight.name == sportsman5.name);
		CHECK(sportsmanMaxWeight.height == sportsman5.height);
		CHECK(sportsmanMaxWeight.weight == sportsman5.weight);
	}

	SECTION("FindMax name")
	{
		Sportsman sportsmanMaxWeight;
		CHECK(FindMax(sportsmanVector, sportsmanMaxWeight, ComparisonName) == true);
		CHECK(sportsmanMaxWeight.name == sportsman4.name);
		CHECK(sportsmanMaxWeight.height == sportsman4.height);
		CHECK(sportsmanMaxWeight.weight == sportsman4.weight);
	}

	SECTION("FindMax empty vector ComparisonHeight")
	{
		Sportsman sportsman;
		std::vector<Sportsman> emptyVector{};
		CHECK(FindMax(emptyVector, sportsman, ComparisonHeight) == false);
		CHECK_NOTHROW(FindMax(emptyVector, sportsman, ComparisonHeight));
	}

	SECTION("FindMax empty vector ComparisonWeight")
	{
		Sportsman sportsman;
		std::vector<Sportsman> emptyVector{};
		CHECK(FindMax(emptyVector, sportsman, ComparisonWeight) == false);
		CHECK_NOTHROW(FindMax(emptyVector, sportsman, ComparisonWeight));
	}

	SECTION("FindMax empty vector ComparisonName")
	{
		Sportsman sportsman;
		std::vector<Sportsman> emptyVector{};
		CHECK(FindMax(emptyVector, sportsman, ComparisonName) == false);
		CHECK_NOTHROW(FindMax(emptyVector, sportsman, ComparisonWeight));
	}
}