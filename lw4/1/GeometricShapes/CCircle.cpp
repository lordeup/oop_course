#include "CCircle.h"

CCircle::CCircle(CPoint& center, const double radius, const std::string outlineColor, const std::string fillColor)
	: m_center(center)
	, m_radius(radius)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

double CCircle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return MULTIPLICATION_FACTOR * M_PI * m_radius;
}

void CCircle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_CIRCLE << std::endl;
	iss << AREA_SHAPE << GetArea() << std::endl;
	iss << PERIMETER_SHAPE << GetPerimeter() << std::endl;
	iss << CENTER_CIRCLE << GetCenter().GetX() << SPACE << GetCenter().GetY() << std::endl;
	iss << RADIUS_CIRCLE << GetRadius() << std::endl;
	iss << OUTLINE_COLOR_SHAPE << GetOutlineColor() << std::endl;
	iss << FILL_COLOR_SHAPE << GetFillColor() << std::endl;
}

std::string CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CCircle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}
