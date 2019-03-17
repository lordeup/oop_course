#include "pch.h"
#include "lw2/1/ProcessVector/ProcessVector.h"
#include "lw2/1/ProcessVector/Vector.h"

TEST_CASE("FindingMinElement Zero")
{
	CHECK(FindingMinElement(vecNumber{ 0.0 }) == 0.0);
}

TEST_CASE("FindingMinElement Not Zero")
{
	CHECK(FindingMinElement(vecNumber{ 235.526, 253.545, 78.23, 12.2, 4.3 }) == 4.3);
}

TEST_CASE("FindingMinElement Minus")
{
	CHECK(FindingMinElement(vecNumber{ -235.526, 253.545, 78.23, -4.3 }) == -235.526);
}

TEST_CASE("ProcessVectorTests Zero")
{
	vecNumber numbers{ 0.0 };
	ProcessVector(numbers);
	CHECK(numbers == vecNumber{ 0.0 });
}

TEST_CASE("ProcessVectorTests Not Zero")
{
	vecNumber numbers = { 18.0, 2.0, 15.0 };
	ProcessVector(numbers);
	CHECK(numbers == vecNumber{ 36.0, 4.0, 30.0 });
}

TEST_CASE("ProcessVectorTests Minus")
{
	vecNumber numbers = { 18.0, -2.0, 15.0, 23.2,  19.0 };
	ProcessVector(numbers);
	CHECK(numbers == vecNumber{ -36.0, 4.0, -30.0, -46.4, -38.0 });
}

TEST_CASE("FillVector")
{
	vecNumber numbers = { 18.0, -2.0, 15.0, 23.2, 19.0 };
	FillVector(numbers);
	CHECK(numbers == vecNumber{ 18.0, -2.0, 15.0, 23.2, 19.0 });
}

//TEST_CASE("FillVector input error")
//{
//	vecNumber numbers{ 23.2, 53.5, 453.8 };
//	CHECK(FillVector(numbers) == false);
//}