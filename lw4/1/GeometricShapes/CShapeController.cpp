#include "CShapeController.h"

CShapeController::CShapeController(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}

std::shared_ptr<CRectangle> CShapeController::CreateRectangle(std::istream& iss)
{
	std::string outlineColor, fillColor;
	double x, y, width, height;

	iss >> x;
	iss >> y;
	iss >> width;
	iss >> height;

	iss >> outlineColor;
	iss >> fillColor;

	CPoint leftTop(x, y);

	return std::make_shared<CRectangle>(leftTop, width, height, outlineColor, fillColor);
}

std::shared_ptr<CTriangle> CShapeController::CreateTriangle(std::istream& iss)
{
	std::string outlineColor, fillColor;
	double x1, y1, x2, y2, x3, y3;

	iss >> x1;
	iss >> y1;

	iss >> x2;
	iss >> y2;

	iss >> x3;
	iss >> y3;

	iss >> outlineColor;
	iss >> fillColor;

	CPoint vertex1(x1, y1);
	CPoint vertex2(x2, y2);
	CPoint vertex3(x3, y3);

	return std::make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
}

std::shared_ptr<CCircle> CShapeController::CreateCircle(std::istream& iss)
{
	std::string outlineColor, fillColor;
	double x, y, radius;

	iss >> x;
	iss >> y;

	iss >> radius;

	iss >> outlineColor;
	iss >> fillColor;

	CPoint center(x, y);

	return std::make_shared<CCircle>(center, radius, outlineColor, fillColor);
}

std::shared_ptr<CLineSegment> CShapeController::CreateLine(std::istream& iss)
{
	std::string outlineColor;
	double x1, y1, x2, y2;

	iss >> x1;
	iss >> y1;

	iss >> x2;
	iss >> y2;

	iss >> outlineColor;

	CPoint startPoint(x1, y1);
	CPoint endPoint(x2, y2);

	return std::make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
}

void CShapeController::ProcessingCommand()
{
	std::string str;

	while (std::getline(m_input, str))
	{
		std::istringstream iss(str);

		std::string figure;
		iss >> figure;
		std::shared_ptr<IShape> shape;

		if (figure == FIGURE_RECTANGLE)
		{
			shape = CreateRectangle(iss);
			m_shape.push_back(shape);
		}
		else if (figure == FIGURE_TRIANGLE)
		{
			shape = CreateTriangle(iss);
			m_shape.push_back(shape);
		}
		else if (figure == FIGURE_CIRCLE)
		{
			shape = CreateCircle(iss);
			m_shape.push_back(shape);
		}
		else if (figure == FIGURE_LINE)
		{
			shape = CreateLine(iss);
			m_shape.push_back(shape);
		}
		else
		{
			m_output << FIGURE_UNKNOWN;
		}
	}
}

void CShapeController::PrintShapeMaxArea()
{
	auto shapeMaxArea = m_shape[0];
	for (const auto& value : m_shape)
	{
		if (value->GetArea() > shapeMaxArea->GetArea())
		{
			shapeMaxArea = value;
		}
	}

	m_output << MAX_AREA_SHAPE;
	shapeMaxArea->PrintInfo(m_output);
	m_output << std::endl;
}

void CShapeController::PrintShapeMinPerimeter()
{
	auto shapeMinPerimeter = m_shape[0];
	for (const auto& value : m_shape)
	{
		if (value->GetPerimeter() < shapeMinPerimeter->GetPerimeter())
		{
			shapeMinPerimeter = value;
		}
	}

	m_output << MIN_PERIMETER_SHAPE;
	shapeMinPerimeter->PrintInfo(m_output);
}

void CShapeController::PrintShapeInfo()
{
	if (m_shape.empty())
	{
		m_output << ERROR_EMPTY_INPUT << std::endl;
	}
	else if (m_shape.size() == 1)
	{
		auto shapeInfo = m_shape[0];
		shapeInfo->PrintInfo(m_output);
	}
	else
	{
		PrintShapeMaxArea();
		PrintShapeMinPerimeter();
	}
}
