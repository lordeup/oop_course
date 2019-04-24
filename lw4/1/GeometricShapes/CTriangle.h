#pragma once
#include "CPoint.h"
#include "Const.h"
#include "ISolidShape.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(CPoint& vertex1, CPoint& vertex2, CPoint& vertex3, const std::string outlineColor, const std::string fillColor);
	virtual ~CTriangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	void PrintInfo(std::ostream& iss) const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	double GetSideCounting(const CPoint& firstPoint, const CPoint& secondPoint) const;

	std::string m_fillColor;
	std::string m_outlineColor;

	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
