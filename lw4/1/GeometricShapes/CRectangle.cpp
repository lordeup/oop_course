#include "CRectangle.h"

CRectangle::CRectangle(CPoint& leftTop, const double width, const double height, const std::string outlineColor, const std::string fillColor)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

void CRectangle::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_RECTANGLE << std::endl;
	iss << AREA_SHAPE << GetArea() << std::endl;
	iss << PERIMETER_SHAPE << GetPerimeter() << std::endl;
	iss << LEFT_TOP_RECTANGLE << GetLeftTop().GetX() << SPACE << GetLeftTop().GetY() << std::endl;
	iss << RIGHT_BOTTOM_RECTANGLE << GetRightBottom().GetX() << SPACE << GetRightBottom().GetY() << std::endl;
	iss << WIDTH_RECTANGLE << GetWidth() << std::endl;
	iss << HEIGHT_RECTANGLE << GetHeight() << std::endl;
	iss << OUTLINE_COLOR_SHAPE << GetOutlineColor() << std::endl;
	iss << FILL_COLOR_SHAPE << GetFillColor() << std::endl;
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * MULTIPLICATION_FACTOR;
}

std::string CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	CPoint rightBottom(m_leftTop.GetX() + m_width, m_leftTop.GetY() + m_height);
	return rightBottom;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
