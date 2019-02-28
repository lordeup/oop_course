#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>

const std::string ERROR_LINE_EMPTY = "The line must be filled";
const std::string ERROR_NUMBER = "You have entered too many numbers, it must be < 255";
const std::string ERROR_ENTER_LINE = "You entered a string, but a number is required";
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

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << ERROR_NOT_ENOUGH_ARGUMENTS << std::endl;
		return 1;
	}

	std::string line = argv[1];

	if (line.empty())
	{
		std::cerr << ERROR_LINE_EMPTY << std::endl;
		return 1;
	}

	int number;

	try
	{
		number = std::stoi(line);
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << ERROR_ENTER_LINE << std::endl;
		return 1;
	}

	if (number < 0 || number > 255)
	{
		std::cout << ERROR_NUMBER << std::endl;
		return 1;
	}

	std::cout << FlipByte(number) << std::endl;

	return 0;
}
