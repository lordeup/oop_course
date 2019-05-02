#pragma once

class CComplex
{
public:
	CComplex(double real, double image);

	double Re() const;
	double Im() const;
	double GetMagnitude() const;
	double GetArgument() const;

	CComplex& operator+(const CComplex& complex);


private:
	double m_real;
	double m_image;

};

CComplex const operator+(const CComplex& complex1, const CComplex& complex2);
CComplex const operator-(const CComplex& complex1, const CComplex& complex2);
CComplex const operator*(const CComplex& complex1, const CComplex& complex2);
CComplex const operator/(const CComplex& complex1, const CComplex& complex2);
