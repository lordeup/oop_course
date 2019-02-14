#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

bool FindTextInFile(std::ifstream& fileInput, std::string& searchString)
{
	bool found = false;
	std::string line;
	int lineNumber{};
	while (getline(fileInput, line))
	{
		++lineNumber;
		if (line.find(searchString) != std::string::npos)
		{
			found = true;
			std::cout << "Line number: " << lineNumber << std::endl;
		}
	}

	return found;
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cerr << "The number of arguments does not match the task condition" << std::endl
				  << "The input should look like <file name> <text to search>" << std::endl;
		return 1;
	}

	std::string fileName = argv[1];
	std::ifstream fileInput(fileName);
	std::string searchString = argv[2];

	if (!fileInput.is_open())
	{
		std::cerr << "This file does not exist" << std::endl;
		return 1;
	}

	if (searchString.empty())
	{
		std::cerr << "The search string must be filled" << std::endl;
		return 1;
	}

	if (!FindTextInFile(fileInput, searchString))
	{
		std::cerr << "Text not found" << std::endl;
		return 1;
	}

	fileInput.close();

	return 0;
}
