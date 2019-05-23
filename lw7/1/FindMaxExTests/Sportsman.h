#pragma once
#include <string>

struct Sportsman
{
	std::string name;
	double height{};
	double weight{};
};

bool ComparisonHeight(const Sportsman& firstSportsman, const Sportsman& secondSportsman);
bool ComparisonWeight(const Sportsman& firstSportsman, const Sportsman& secondSportsman);
bool ComparisonName(const Sportsman& firstSportsman, const Sportsman& secondSportsman);