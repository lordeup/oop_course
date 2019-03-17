#include "pch.h"
#include "ProcessVector.h"

double FindingMinElement(const vecNumber& numbers)
{
	return (*(std::min_element(numbers.begin(), numbers.end())));
}

void ProcessVector(vecNumber& numbers)
{
	double minValue = FindingMinElement(numbers);
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		numbers[i] *= minValue;
	}
}
