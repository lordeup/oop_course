#include "pch.h"
#include "CShapeController.h"
#include "Const.h"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << ERROR_NOT_ENOUGH_ARGUMENTS;
		return 1;
	}

	std::ifstream fileInput(argv[1]);

	if (!fileInput.is_open())
	{
		std::cerr << ERROR_FILE_NOT_EXIST << std::endl;
		return 1;
	}

	CShapeController shapeController(fileInput, std::cout);

	while (!fileInput.eof())
	{
		shapeController.ProcessingCommand();
	}

	shapeController.PrintShapeMaxArea();
	shapeController.PrintShapeMinPerimeter();

	return 0;
}
