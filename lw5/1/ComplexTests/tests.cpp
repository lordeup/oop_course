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

TEST_CASE("operator")
{
	SECTION("+ binary")
	{
		CComplex complex1(1.5, 1.0);
		CComplex complex2(1.0, 2.0);

		CComplex complexResult = complex1 + complex2;
		CHECK(complexResult.Re() == 2.5);
		CHECK(complexResult.Im() == 3.0);
	}

	SECTION("+ unary")
	{
		CComplex complex(1.5, 1.0);

		CComplex complexResult = +complex;
		CHECK(complexResult.Re() == 1.5);
		CHECK(complexResult.Im() == 1.0);
	}

	SECTION("- binary")
	{
		CComplex complex1(1.5, 1.0);
		CComplex complex2(1.0, 2.0);

		CComplex complexResult = complex1 - complex2;
		CHECK(complexResult.Re() == 0.5);
		CHECK(complexResult.Im() == -1.0);
	}

	SECTION("- unary")
	{
		CComplex complex(2.7, 5.1);

		CComplex complexResult = -complex;
		CHECK(complexResult.Re() == -2.7);
		CHECK(complexResult.Im() == -5.1);
	}

	SECTION("* binary")
	{
		CComplex complex1(1.0, 2.0);
		CComplex complex2(2.0, 3.0);

		CComplex complexResult = complex1 * complex2;
		CHECK(complexResult.Re() == -4.0);
		CHECK(complexResult.Im() == 7.0);
	}

	SECTION("/ binary")
	{
		CComplex complex1(1.0, 4.5);
		CComplex complex2(1.0, 3.0);

		CComplex complexResult = complex1 / complex2;
		CHECK(complexResult.Re() == 1.45);
		CHECK(complexResult.Im() == 0.15);
	}

	SECTION("+=")
	{
		CComplex complex1(1.5, 2.1);
		CComplex complex2(3.6, 5.0);

		complex1 += complex2;
		CHECK(complex1.Re() == 5.1);
		CHECK(complex1.Im() == 7.1);
	}

	SECTION("-=")
	{
		CComplex complex1(7.0, 1.5);
		CComplex complex2(2.1, 8.0);

		complex1 -= complex2;
		CHECK(complex1.Re() == 4.9);
		CHECK(complex1.Im() == -6.5);
	}

	SECTION("*=")
	{
		CComplex complex1(1.0, 2.0);
		CComplex complex2(1.0, 5.0);

		complex1 *= complex2;
		CHECK(complex1.Re() == -9.0);
		CHECK(complex1.Im() == 7.0);
	}

	SECTION("/=")
	{
		CComplex complex1(1.0, 2.0);
		CComplex complex2(2.0, 4.0);

		complex1 /= complex2;
		CHECK(complex1.Re() == 0.5);
		CHECK(complex1.Im() == 0.0);
	}

	SECTION("==")
	{
		CComplex complex1(1.1, 2.0);
		CComplex complex2(1.1, 2.0);

		bool checkResult1 = (complex1 == complex2);
		CHECK(checkResult1 == true);

		CComplex complex3(1.15, 2.0);
		CComplex complex4(1.20, 2.0);

		bool checkResult2 = (complex3 == complex4);
		CHECK(checkResult2 == false);
	}

	SECTION("!=")
	{
		CComplex complex1(1.15, 2.0);
		CComplex complex2(1.20, 2.0);

		bool checkResult1 = (complex1 != complex2);
		CHECK(checkResult1 == true);

		CComplex complex3(1.1, 2.0);
		CComplex complex4(1.1, 2.0);

		bool checkResult2 = (complex3 != complex4);
		CHECK(checkResult2 == false);
	}

	SECTION("<<")
	{
		CComplex complex1(-3.5, -4.8);
		std::stringstream output1;
		output1 << complex1;
		CHECK(output1.str() == "-3.5-4.8i");

		CComplex complex2(4.0, 2.0);
		std::stringstream output2;
		output2 << complex2;
		CHECK(output2.str() == "4+2i");

		CComplex complex3(-3.0, 2.0);
		std::stringstream output3;
		output3 << complex3;
		CHECK(output3.str() == "-3+2i");

		CComplex complex4(3.0, -2.0);
		std::stringstream output4;
		output4 << complex4;
		CHECK(output4.str() == "3-2i");
	}

	SECTION(">>")
	{
		CComplex complex1;
		std::stringstream input1("-3.5-4.8i");
		input1 >> complex1;
		CHECK(complex1.Re() == -3.5);
		CHECK(complex1.Im() == -4.8);

		CComplex complex2;
		std::stringstream input2("4+2i");
		input2 >> complex2;
		CHECK(complex2.Re() == 4.0);
		CHECK(complex2.Im() == 2.0);

		CComplex complex3;
		std::stringstream input3("-3+2i");
		input3 >> complex3;
		CHECK(complex3.Re() == -3.0);
		CHECK(complex3.Im() == 2.0);

		CComplex complex4;
		std::stringstream input4("3-2i");
		input4 >> complex4;
		CHECK(complex4.Re() == 3.0);
		CHECK(complex4.Im() == -2.0);
	}
}
