#include "Car.h"
#include "CarCommunication.h"
#include <iostream>

int main()
{
	CCar car;
	CCarCommunication carCommunication(std::cin, std::cout, car);

	while (!std::cin.eof())
	{
		carCommunication.ProcessingCommand();
	}

	return 0;
}
