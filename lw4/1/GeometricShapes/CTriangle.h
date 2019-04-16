#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(const uint32_t fillColor, const uint32_t outlineColor, CPoint& vertex1, CPoint& vertex2, CPoint& vertex3);
	virtual ~CTriangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	//std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	double GetSideCounting(const CPoint& firstPoint, const CPoint& secondPoint) const;

	uint32_t m_fillColor;
	uint32_t m_outlineColor;
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
