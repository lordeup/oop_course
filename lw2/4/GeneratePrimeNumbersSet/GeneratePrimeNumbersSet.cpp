#include "pch.h"
#include "Primes.h"
#include <iostream>

void PrintPrimeNumbers(std::set<int>& primes)
{
	for (auto prime : primes)
	{
		std::cout << prime << " ";
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << ERROR_NOT_ENOUGH_ARGUMENTS << std::endl;
		return 1;
	}

	int upperBound;

	try
	{
		upperBound = std::stoi(argv[1]);
	}
	catch (const std::invalid_argument&)
	{
		std::cerr << ERROR_VALUE_NUMBER << std::endl;
		return 1;
	}

	if ((upperBound <= 0) || (upperBound > MAX_SIZE))
	{
		std::cerr << ERROR_VALUE_NUMBER << std::endl;
		return 1;
	}

	if (upperBound < 2)
	{
		return 1;
	}

	std::set<int> prime = GeneratePrimeNumbersSet(upperBound);

	PrintPrimeNumbers(prime);

	return 0;
}
