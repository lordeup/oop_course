#include "CLineSegment.h"

CLineSegment::CLineSegment(CPoint& startPoint, CPoint& endPoint, const std::string outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_outlineColor(outlineColor)
{
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return sqrt(pow(m_endPoint.GetX() - m_startPoint.GetX(), POWER_NUMBER) + pow(m_endPoint.GetY() - m_startPoint.GetY(), POWER_NUMBER));
}

void CLineSegment::PrintInfo(std::ostream& iss) const
{
	iss << FIGURE_LINE << std::endl;
	iss << AREA_SHAPE << GetArea() << std::endl;
	iss << PERIMETER_SHAPE << GetPerimeter() << std::endl;
	iss << START_POINT_LINE << GetStartPoint().GetX() << SPACE << GetStartPoint().GetY() << std::endl;
	iss << END_POINT_LINE << GetEndPoint().GetX() << SPACE << GetEndPoint().GetY() << std::endl;
	iss << OUTLINE_COLOR_SHAPE << GetOutlineColor() << std::endl;
}

std::string CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}
