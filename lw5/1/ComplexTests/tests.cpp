#define CATCH_CONFIG_MAIN
#include "../../1/Complex/CComplex.h"
#include <catch2/catch.hpp>

TEST_CASE("CComplex")
{
	SECTION("Re")
	{
		double real = 5.0, image = 9.1;
		CComplex complex(real, image);
		CHECK(complex.Re() == real);
	}

	SECTION("Im")
	{
		double real = 2.1, image = 8.9;
		CComplex complex(real, image);
		CHECK(complex.Im() == image);
	}

	SECTION("GetMagnitude")
	{
		double real = 3.0, image = 4.0;
		CComplex complex(real, image);
		CHECK(complex.GetMagnitude() == 5.0);
	}

	SECTION("GetArgument")
	{
		double real = 15.3, image = 1.0;
		CComplex complex(real, image);
		double arg = atan2(image, real);
		CHECK(complex.GetArgument() == arg);
	}

	SECTION("GetArgument negative real")
	{
		double real = -1.3, image = 5.0;
		CComplex complex(real, image);
		double arg = atan2(image, real);
		CHECK(complex.GetArgument() == arg);
	}

	SECTION("GetArgument negative image")
	{
		double real = 2.1, image = -4.0;
		CComplex complex(real, image);
		double arg = atan2(image, real);
		CHECK(complex.GetArgument() == arg);
	}

	SECTION("GetArgument negative real, image")
	{
		double real = -5.3, image = -7.3;
		CComplex complex(real, image);
		double arg = atan2(image, real);
		CHECK(complex.GetArgument() == arg);
	}

	SECTION("GetArgument zero")
	{
		double real = 1.9, image = 0.0;
		CComplex complex(real, image);
		CHECK(complex.GetArgument() == 0.0);
	}
}

//TEST_CASE("operator")
//{
//
//}
