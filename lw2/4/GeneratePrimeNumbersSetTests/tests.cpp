#include "pch.h"
#include "../../4/GeneratePrimeNumbersSet/Primes.h"


TEST_CASE("InitVectorOfPrimes test")
{
	std::vector<bool> outVecOne = { false, false, true };
	CHECK(InitVectorOfPrimes(2) == outVecOne);

	std::vector<bool> outVecTwo = { false, false, true, true, false, true, false };
	CHECK(InitVectorOfPrimes(6) == outVecTwo);

	std::vector<bool> outVecThree = { false, false, true, true, false, true, false, true, false, false, false };
	CHECK(InitVectorOfPrimes(10) == outVecThree);
}

TEST_CASE("GeneratePrimeNumbersSet test size")
{
	CHECK(GeneratePrimeNumbersSet(2).size() == 1);
	CHECK(GeneratePrimeNumbersSet(20).size() == 8);
	CHECK(GeneratePrimeNumbersSet(100).size() == 25);
}

TEST_CASE("GeneratePrimeNumbersSet test element")
{
	std::set<int> outSetOne = { 2 };
	CHECK(GeneratePrimeNumbersSet(2) == outSetOne);

	std::set<int> outSetTwo = { 2, 3, 5, 7, 11, 13, 17, 19 };
	CHECK(GeneratePrimeNumbersSet(20) == outSetTwo);

	std::set<int> outSetThree = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	CHECK(GeneratePrimeNumbersSet(100) == outSetThree);
}

TEST_CASE("GeneratePrimeNumbersSet test max size")
{
	CHECK(GeneratePrimeNumbersSet(MAX_SIZE).size() == 5761455);
}
