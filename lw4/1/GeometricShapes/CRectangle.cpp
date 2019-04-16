#include "CRectangle.h"

CRectangle::CRectangle(const uint32_t fillColor, const uint32_t outlineColor, CPoint& leftTop, CPoint& rightBottom, const double width, const double height)
	: m_fillColor(fillColor)
	, m_outlineColor(outlineColor)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
	, m_width(width)
	, m_height(height)
{
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
