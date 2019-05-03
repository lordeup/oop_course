#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <float.h>
#include <sstream>

class CComplex
{
public:
	CComplex() = default;
	CComplex(double real, double image);

	double Re() const;
	double Im() const;
	double GetMagnitude() const;
	double GetArgument() const;

	CComplex const operator+() const;
	CComplex const operator-() const;

	CComplex& operator+=(const CComplex& complex);
	CComplex& operator-=(const CComplex& complex);
	CComplex& operator*=(const CComplex& complex);
	CComplex& operator/=(const CComplex& complex);

private:
	double m_real;
	double m_image;
};

CComplex const operator+(const CComplex& complex1, const CComplex& complex2);
CComplex const operator-(const CComplex& complex1, const CComplex& complex2);
CComplex const operator*(const CComplex& complex1, const CComplex& complex2);
CComplex const operator/(const CComplex& complex1, const CComplex& complex2);

bool operator==(const CComplex& complex1, const CComplex& complex2);
bool operator!=(const CComplex& complex1, const CComplex& complex2);

std::ostream& operator<<(std::ostream& output, const CComplex& complex);
std::istream& operator>>(std::istream& input, CComplex& complex);
