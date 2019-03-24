#pragma once

#include <set>
#include <string>
#include <vector>

const long long MAX_SIZE = 100000000;
const int FIRST_PRIME = 2;

const std::string ERROR_VALUE_NUMBER = "The value must be a number from 1 to 100000000";
const std::string ERROR_NOT_ENOUGH_ARGUMENTS = "The number of arguments does not match the task condition\n"
											   "Input should look: GeneratePrimeNumbersSet.exe <upperBound>";

std::vector<bool> InitVectorOfPrimes(int upperBound);
std::set<int> GeneratePrimeNumbersSet(int upperBound);
