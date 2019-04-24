#pragma once
#include "CPoint.h"
#include "Const.h"
#include "ISolidShape.h"

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint& center, const double radius, const std::string outlineColor, const std::string fillColor);
	virtual ~CCircle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	void PrintInfo(std::ostream& iss) const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	CPoint GetCenter() const;
	double GetRadius() const;

private:
	const double M_PI = 3.14;

	double m_radius;

	std::string m_fillColor;
	std::string m_outlineColor;

	CPoint m_center;
};
