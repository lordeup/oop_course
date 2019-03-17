#include "pch.h"
#include "Vector.h"

int main()
{
	vecNumber numbers;

	if (!FillVector(numbers))
	{
		std::cerr << ERROR_VALUE_NUMBER << std::endl;
		return 1;
	}

	ProcessVector(numbers);

	sort(numbers.begin(), numbers.end());

	PrintVector(numbers);

	return 0;
}
