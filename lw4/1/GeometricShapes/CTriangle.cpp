#include "CTriangle.h"

CTriangle::CTriangle(CPoint& vertex1, CPoint& vertex2, CPoint& vertex3, const std::string outlineColor, const std::string fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

double CTriangle::GetSideCounting(const CPoint& firstPoint, const CPoint& secondPoint) const
{
	return sqrt(pow(secondPoint.GetX() - firstPoint.GetX(), POWER_NUMBER) + pow(secondPoint.GetY() - firstPoint.GetY(), POWER_NUMBER));
}

void CTriangle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_TRIANGLE << std::endl;
	iss << AREA_SHAPE << GetArea() << std::endl;
	iss << PERIMETER_SHAPE << GetPerimeter() << std::endl;
	iss << VERTEX_1_TRIANGLE << GetVertex1().GetX() << SPACE << GetVertex1().GetY() << std::endl;
	iss << VERTEX_2_TRIANGLE << GetVertex2().GetX() << SPACE << GetVertex2().GetY() << std::endl;
	iss << VERTEX_3_TRIANGLE << GetVertex3().GetX() << SPACE << GetVertex3().GetY() << std::endl;
	iss << OUTLINE_COLOR_SHAPE << GetOutlineColor() << std::endl;
	iss << FILL_COLOR_SHAPE << GetFillColor() << std::endl;
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

	double semiPerimeter = (side1 + side2 + side3) / MULTIPLICATION_FACTOR;
	return sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
}

std::string CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CTriangle::GetFillColor() const
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
