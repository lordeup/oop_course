#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

class CCircle : public ISolidShape
{
public:
	CCircle(const uint32_t fillColor, const uint32_t outlineColor, CPoint& center, const double radius);
	virtual ~CCircle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	//std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	CPoint GetCenter() const;
	double GetRadius() const;

private:
	const double M_PI = 3.14;

	uint32_t m_fillColor;
	uint32_t m_outlineColor;

	CPoint m_center;
	double m_radius;
};
