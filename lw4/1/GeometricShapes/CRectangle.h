#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(const uint32_t fillColor, const uint32_t outlineColor, CPoint& leftTop, CPoint& rightBottom, const double width, const double height);
	virtual ~CRectangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	//std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	uint32_t m_fillColor;
	uint32_t m_outlineColor;
	CPoint m_leftTop;
	CPoint m_rightBottom;
	double m_width;
	double m_height;
};
