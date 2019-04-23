#pragma once
#include "CCircle.h"
#include "CLineSegment.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "Const.h"
#include "IShape.h"
#include <vector>

class CShapeController
{
public:
	CShapeController(std::istream& input, std::ostream& output);

	void ProcessingCommand();
	void PrintShapeMaxArea();
	void PrintShapeMinPerimeter();

private:
	std::shared_ptr<CRectangle> CreateRectangle(std::istream& iss);
	std::shared_ptr<CTriangle> CreateTriangle(std::istream& iss);
	std::shared_ptr<CCircle> CreateCircle(std::istream& iss);
	std::shared_ptr<CLineSegment> CreateLine(std::istream& iss);

	std::istream& m_input;
	std::ostream& m_output;

	std::vector<std::shared_ptr<IShape>> m_shape;
};
