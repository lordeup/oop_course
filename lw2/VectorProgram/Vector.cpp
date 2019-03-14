#include "pch.h"
#include "Vector.h"

bool FillVector(vecNumber& numbers)
{
	double number;

	std::string str;
	std::getline(std::cin, str);
	std::istringstream iss(str);

	try
	{
		number = std::stoi(str);
	}
	catch (const std::invalid_argument&)
	{
		return false;
	}

	while (iss >> number)
	{
		numbers.push_back(number);
	}

	return true;
}

void PrintVector(vecNumber& numbers)
{
	for (auto number : numbers)
	{
		std::cout << std::fixed << std::setprecision(ROUNDING_FACTOR) << number << " ";
	}
}