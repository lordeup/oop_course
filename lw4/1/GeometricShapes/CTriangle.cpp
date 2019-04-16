#include "CTriangle.h"

CTriangle::CTriangle(const uint32_t fillColor, const uint32_t outlineColor, CPoint& vertex1, CPoint& vertex2, CPoint& vertex3)
	: m_fillColor(fillColor)
	, m_outlineColor(outlineColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

double CTriangle::GetSideCounting(const CPoint& firstPoint, const CPoint& secondPoint) const
{
	return sqrt(pow(secondPoint.GetX() - firstPoint.GetX(), 2) + pow(secondPoint.GetY() - firstPoint.GetY(), 2));
}

double CTriangle::GetPerimeter() const
{
	double side1 = GetSideCounting(m_vertex1, m_vertex2);
	double side2 = GetSideCounting(m_vertex2, m_vertex3);
	double side3 = GetSideCounting(m_vertex1, m_vertex3);

	return side1 + side2 + side3;
}

double CTriangle::GetArea() const
{
	double side1 = GetSideCounting(m_vertex1, m_vertex2);
	double side2 = GetSideCounting(m_vertex2, m_vertex3);
	double side3 = GetSideCounting(m_vertex1, m_vertex3);

	double semiPerimeter = (side1 + side2 + side3) * 0.5;
	return sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}
