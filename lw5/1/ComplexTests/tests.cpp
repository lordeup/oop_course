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

		double real2 = 0.0, image2 = 0.0;
		CComplex complex2(real2, image2);
		CHECK(complex2.GetArgument() == 0.0);
	}
}

TEST_CASE("operator")
{
	SECTION("+ binary")
	{
		CComplex complex1(1.5, 1.0);
		CComplex complex2(1.0, 2.0);
		CComplex complex3(3.0, 4.0);

		CComplex complexResult1 = complex1 + complex2;
		CHECK(complexResult1.Re() == 2.5);
		CHECK(complexResult1.Im() == 3.0);

		CComplex complexResult2 = complex3 + 5.0;
		CHECK(complexResult2.Re() == 8.0);
		CHECK(complexResult2.Im() == 4.0);

		CComplex complexResult3 = 4.0 + complex3;
		CHECK(complexResult3.Re() == 7.0);
		CHECK(complexResult3.Im() == 4.0);
	}

	SECTION("- binary")
	{
		CComplex complex1(1.5, 1.0);
		CComplex complex2(1.0, 2.0);
		CComplex complex3(3.0, 4.0);

		CComplex complexResult1 = complex1 - complex2;
		CHECK(complexResult1.Re() == 0.5);
		CHECK(complexResult1.Im() == -1.0);

		CComplex complexResult2 = complex3 - 4.0;
		CHECK(complexResult2.Re() == -1.0);
		CHECK(complexResult2.Im() == 4.0);

		CComplex complexResult3 = 3.0 - complex3;
		CHECK(complexResult3.Re() == 0.0);
		CHECK(complexResult3.Im() == -4.0);
	}

	SECTION("+ unary")
	{
		CComplex complex(1.5, 1.0);

		CComplex complexResult1 = +complex;
		CHECK(complexResult1.Re() == 1.5);
		CHECK(complexResult1.Im() == 1.0);

		CComplex complexResult2 = +2.1;
		CHECK(complexResult2.Re() == 2.1);
		CHECK(complexResult2.Im() == 0.0);
	}

	SECTION("- unary")
	{
		CComplex complex(2.7, 5.1);

		CComplex complexResult = -complex;
		CHECK(complexResult.Re() == -2.7);
		CHECK(complexResult.Im() == -5.1);

		CComplex complexResult2 = -4.2;
		CHECK(complexResult2.Re() == -4.2);
		CHECK(complexResult2.Im() == 0.0);
	}

	SECTION("*")
	{
		CComplex complex1(1.0, 2.0);
		CComplex complex2(2.0, 3.0);
		CComplex complex3(3.0, 4.0);

		CComplex complexResult = complex1 * complex2;
		CHECK(complexResult.Re() == -4.0);
		CHECK(complexResult.Im() == 7.0);

		CComplex complexResult2 = complex3 * 4.0;
		CHECK(complexResult2.Re() == 12.0);
		CHECK(complexResult2.Im() == 16.0);

		CComplex complexResult3 = 2.0 * complex3;
		CHECK(complexResult3.Re() == 6.0);
		CHECK(complexResult3.Im() == 8.0);
	}

	SECTION("/")
	{
		CComplex complex1(1.0, 4.5);
		CComplex complex2(1.0, 3.0);
		CComplex complex3(3.0, 4.0);

		CComplex complexResult = complex1 / complex2;
		CHECK(complexResult.Re() == 1.45);
		CHECK(complexResult.Im() == 0.15);

		CComplex complexResult2 = complex3 / 4.0;
		CHECK(complexResult2.Re() == 0.75);
		CHECK(complexResult2.Im() == 1.0);

		CComplex complexResult3 = 2.0 / complex3;
		CHECK(complexResult3.Re() == 0.24);
		CHECK(complexResult3.Im() == -0.32);
	}

	SECTION("+=")
	{
		CComplex complex1(1.5, 2.1);
		CComplex complex2(3.6, 5.0);
		CComplex complex3(3.0, 4.0);

		complex1 += complex2;
		CHECK(complex1.Re() == 5.1);
		CHECK(complex1.Im() == 7.1);

		complex3 += 1.1;
		CHECK(complex3.Re() == 4.1);
		CHECK(complex3.Im() == 4.0);
	}

	SECTION("-=")
	{
		CComplex complex1(7.0, 1.5);
		CComplex complex2(2.1, 8.0);
		CComplex complex3(3.0, 4.0);

		complex1 -= complex2;
		CHECK(complex1.Re() == 4.9);
		CHECK(complex1.Im() == -6.5);

		complex3 -= 1.1;
		CHECK(complex3.Re() == 1.9);
		CHECK(complex3.Im() == 4.0);
	}

	SECTION("*=")
	{
		CComplex complex1(1.0, 2.0);
		CComplex complex2(1.0, 5.0);
		CComplex complex3(3.0, 4.0);

		complex1 *= complex2;
		CHECK(complex1.Re() == -9.0);
		CHECK(complex1.Im() == 7.0);

		complex3 *= 3.5;
		CHECK(complex3.Re() == 10.5);
		CHECK(complex3.Im() == 14.0);
	}

	SECTION("/=")
	{
		CComplex complex1(1.0, 2.0);
		CComplex complex2(2.0, 4.0);
		CComplex complex3(3.0, 4.0);

		complex1 /= complex2;
		CHECK(complex1.Re() == 0.5);
		CHECK(complex1.Im() == 0.0);

		complex3 /= 2.0;
		CHECK(complex3.Re() == 1.5);
		CHECK(complex3.Im() == 2.0);
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

		CComplex complex5(1.0, 0.0);
		std::stringstream output5;
		output5 << complex5;
		CHECK(output5.str() == "1+0i");
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

		CComplex complex5;
		std::stringstream input5("1-14");
		CHECK_THROWS_AS(input5 >> complex5, std::invalid_argument);

		CComplex complex6;
		std::stringstream input6("hello");
		CHECK_THROWS_AS(input6 >> complex6, std::invalid_argument);
	}
}
