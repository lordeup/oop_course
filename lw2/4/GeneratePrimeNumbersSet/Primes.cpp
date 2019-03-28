#include "pch.h"
#include "Primes.h"

std::vector<bool> InitVectorOfPrimes(int upperBound)
{
	std::vector<bool> prime(upperBound + 1, true);
	prime[0] = prime[1] = false;
	for (int i = FIRST_PRIME; i * i <= upperBound; ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= upperBound; j += i)
			{
				prime[j] = false;
			}
		}
	}

	return prime;
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::vector<bool> prime = InitVectorOfPrimes(upperBound);
	std::set<int> result;

	result.insert(FIRST_PRIME);
	for (int i = FIRST_PRIME + 1; i <= upperBound; i += 2)
	{
		if (prime[i])
		{
			result.insert(i);
		}
	}

	return result;
}
