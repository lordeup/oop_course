#include "CComplex.h"
#define _USE_MATH_DEFINES
#include <cmath>

CComplex::CComplex(double real, double image)
	: m_real(real)
	, m_image(image)
{
}

double CComplex::Re() const
{
	return m_real;
}

double CComplex::Im() const
{
	return m_image;
}

double CComplex::GetMagnitude() const
{
	return sqrt(pow(m_real, 2) + pow(m_image, 2));
}

double CComplex::GetArgument() const
{
	return atan2(m_image, m_real);
}

CComplex const operator+(const CComplex& complex1, const CComplex& complex2)
{
	return CComplex(complex1.Re() + complex2.Re(), complex1.Im() + complex2.Im());
}

CComplex const operator-(const CComplex& complex1, const CComplex& complex2)
{
	return CComplex(complex1.Re() - complex2.Re(), complex1.Im() - complex2.Im());
}

CComplex const operator*(const CComplex& complex1, const CComplex& complex2)
{
	return CComplex(complex1.Re() * complex2.Re() - complex1.Im() * complex2.Im(), complex1.Re() * complex2.Im() + complex1.Im() * complex2.Re());
}

CComplex const operator/(const CComplex& complex1, const CComplex& complex2)
{
	double dividend = pow(complex2.Re(), 2) + pow(complex2.Im(), 2);
	return CComplex((complex1.Re() * complex2.Re() + complex1.Im() * complex2.Im()) / dividend, (complex1.Im() * complex2.Re() - complex1.Re() * complex2.Im()) / dividend);
}
