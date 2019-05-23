#include "../../1/FindMaxExTests/Sportsman.h"

bool ComparisonHeight(const Sportsman& firstSportsman, const Sportsman& secondSportsman)
{
	return firstSportsman.height < secondSportsman.height;
}

bool ComparisonWeight(const Sportsman& firstSportsman, const Sportsman& secondSportsman)
{
	return firstSportsman.weight < secondSportsman.weight;
}

bool ComparisonName(const Sportsman& firstSportsman, const Sportsman& secondSportsman)
{
	return firstSportsman.name < secondSportsman.name;
}