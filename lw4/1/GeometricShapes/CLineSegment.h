#pragma once
#include "CPoint.h"
#include "IShape.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(const uint32_t outlineColor, CPoint& startPoint, CPoint& endPoint);
	virtual ~CLineSegment() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	//std::string ToString() const override;
	uint32_t GetOutlineColor() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	uint32_t m_outlineColor;

	CPoint m_startPoint;
	CPoint m_endPoint;
};
