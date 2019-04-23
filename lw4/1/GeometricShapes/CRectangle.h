#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint& leftTop, const double width, const double height, const std::string outlineColor, const std::string fillColor);
	virtual ~CRectangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	void PrintInfo(std::ostream& iss) const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	double m_width;
	double m_height;

	std::string m_fillColor;
	std::string m_outlineColor;

	CPoint m_leftTop;
};
