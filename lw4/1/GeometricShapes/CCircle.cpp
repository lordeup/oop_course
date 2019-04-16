#include "CCircle.h"

CCircle::CCircle(const uint32_t fillColor, const uint32_t outlineColor, CPoint& center, const double radius)
	: m_fillColor(fillColor)
	, m_outlineColor(outlineColor)
	, m_center(center)
	, m_radius(radius)

{
}

double CCircle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

uint32_t CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
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
