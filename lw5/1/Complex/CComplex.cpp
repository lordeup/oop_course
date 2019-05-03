#include "CComplex.h"

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

CComplex const CComplex::operator+() const
{
	return CComplex(m_real, m_image);
}

CComplex const CComplex::operator-() const
{
	return CComplex(-m_real, -m_image);
}

CComplex& CComplex::operator+=(const CComplex& complex)
{
	m_real += complex.m_real;
	m_image += complex.m_image;
	return *this;
}

CComplex& CComplex::operator-=(const CComplex& complex)
{
	m_real -= complex.m_real;
	m_image -= complex.m_image;
	return *this;
}

CComplex& CComplex::operator*=(const CComplex& complex)
{
	double temporaryReal = m_real;
	m_real = m_real * complex.m_real - m_image * complex.m_image;
	m_image = m_image * complex.m_real + temporaryReal * complex.m_image;
	return *this;
}

CComplex& CComplex::operator/=(const CComplex& complex)
{
	double temporaryReal = m_real;
	double dividend = pow(complex.m_real, 2) + pow(complex.m_image, 2);
	m_real = (m_real * complex.m_real + m_image * complex.m_image) / dividend;
	m_image = (m_image * complex.m_real - temporaryReal * complex.m_image) / dividend;
	return *this;
}

bool operator==(const CComplex& complex1, const CComplex& complex2)
{
	bool realCheckEqual = (fabs(complex1.Re() - complex2.Re()) < DBL_EPSILON);
	bool imageCheckEqual = (fabs(complex1.Im() - complex2.Im()) < DBL_EPSILON);

	return realCheckEqual && imageCheckEqual;
}

bool operator!=(const CComplex& complex1, const CComplex& complex2)
{
	return !(complex1 == complex2);
}

std::ostream& operator<<(std::ostream& output, const CComplex& complex)
{
	output << complex.Re();

	if (complex.Im() > 0.0)
	{
		output << "+";
	}

	output << complex.Im() << "i";
	return output;
}

std::istream& operator>>(std::istream& input, CComplex& complex)
{
	double real{}, image{};
	input >> real >> image;

	complex = CComplex(real, image);

	return input;
}
