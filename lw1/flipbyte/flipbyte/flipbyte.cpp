#include "pch.h"
#include <iostream>
#include <string>

const std::string ERROR_VALUE_NUMBER = "The value must be a number from 0 to 255";
const std::string ERROR_NOT_ENOUGH_ARGUMENTS = "The number of arguments does not match the task condition\n"
											   "Input should look: flipbyte.exe <input byte>";

unsigned int FlipByte(unsigned int number)
{
	unsigned int resultByte = 0;
	for (int i = 0; i < 8; ++i)
	{
		resultByte = resultByte << 1;
		resultByte = resultByte | number & 1;
		number = number >> 1;
	}
	return resultByte;
}

bool IsCorrectNumber(std::string& line, int& number)
{
	try
	{
		number = std::stoi(line);
	}
	catch (const std::invalid_argument& err)
	{
		return false;
	}

	if (number < 0 || number > 255)
	{
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << ERROR_NOT_ENOUGH_ARGUMENTS << std::endl;
		return 1;
	}

	std::string line = argv[1];
	int number;

	if (!IsCorrectNumber(line, number))
	{
		std::cout << ERROR_VALUE_NUMBER << std::endl;
		return 1;
	}

	std::cout << FlipByte(number) << std::endl;

	return 0;
}
