#define CATCH_CONFIG_MAIN
#include "../../1/GeometricShapes/CCircle.h"
#include "../../1/GeometricShapes/CLineSegment.h"
#include "../../1/GeometricShapes/CPoint.h"
#include "../../1/GeometricShapes/CRectangle.h"
#include "../../1/GeometricShapes/CShapeController.h"
#include "../../1/GeometricShapes/CTriangle.h"
#include <catch2/catch.hpp>

TEST_CASE("Shape")
{
	SECTION("CPoint")
	{
		CPoint point(15.15, 19.85);
		CHECK(point.GetX() == 15.15);
		CHECK(point.GetY() == 19.85);
	}

	SECTION("CRectangle")
	{
		CPoint leftTop(535.0, 300.0);
		double width = 545.0, height = 400.0;
		std::string outlineColor = "ffd700", fillColor = "ff0000";
		CRectangle rectangle(leftTop, width, height, outlineColor, fillColor);

		CHECK(rectangle.GetArea() == 218000.0);
		CHECK(rectangle.GetPerimeter() == 1890.0);
		CHECK(rectangle.GetWidth() == width);
		CHECK(rectangle.GetHeight() == height);
		CHECK(rectangle.GetLeftTop().GetX() == leftTop.GetX());
		CHECK(rectangle.GetLeftTop().GetY() == leftTop.GetY());

		CHECK(rectangle.GetRightBottom().GetX() == 1080.0);
		CHECK(rectangle.GetRightBottom().GetY() == 700.0);

		std::stringstream issOut;
		std::stringstream issOutCheck("rectangle\nArea 218000\nPerimeter 1890\nLeft top 535 300\nRight bottom 1080 700\nWidth 545\nHeight 400\nOutline color ffd700\nFill color ff0000\n");

		rectangle.PrintInfo(issOut);
		CHECK(issOut.str() == issOutCheck.str());

		CHECK(rectangle.GetFillColor() == "ff0000");
		CHECK(rectangle.GetOutlineColor() == "ffd700");
	}

	SECTION("CTriangle")
	{
		CPoint vertex1(0.0, 0.0);
		CPoint vertex2(0.0, 3.0);
		CPoint vertex3(4.0, 3.0);
		std::string outlineColor = "ffd700", fillColor = "ff0000";
		CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);

		CHECK(triangle.GetArea() == 6.0);
		CHECK(triangle.GetPerimeter() == 12.0);

		CHECK(triangle.GetVertex1().GetX() == vertex1.GetX());
		CHECK(triangle.GetVertex1().GetY() == vertex1.GetY());

		CHECK(triangle.GetVertex2().GetX() == vertex2.GetX());
		CHECK(triangle.GetVertex2().GetY() == vertex2.GetY());

		CHECK(triangle.GetVertex3().GetX() == vertex3.GetX());
		CHECK(triangle.GetVertex3().GetY() == vertex3.GetY());

		std::stringstream issOut;
		std::stringstream issOutCheck("triangle\nArea 6\nPerimeter 12\nVertex1 0 0\nVertex2 0 3\nVertex3 4 3\nOutline color ffd700\nFill color ff0000\n");

		triangle.PrintInfo(issOut);
		CHECK(issOut.str() == issOutCheck.str());

		CHECK(triangle.GetFillColor() == "ff0000");
		CHECK(triangle.GetOutlineColor() == "ffd700");
	}

	SECTION("CCircle")
	{
		CPoint center(0.0, 0.0);
		double radius = 15.5;
		std::string outlineColor = "ffd700", fillColor = "ff0000";
		CCircle circle(center, radius, outlineColor, fillColor);

		CHECK(circle.GetArea() == 754.385);
		CHECK(circle.GetPerimeter() == 97.34);
		CHECK(circle.GetRadius() == radius);
		CHECK(circle.GetCenter().GetX() == center.GetX());
		CHECK(circle.GetCenter().GetY() == center.GetY());

		std::stringstream issOut;
		std::stringstream issOutCheck("circle\nArea 754.385\nPerimeter 97.34\nCenter 0 0\nRadius 15.5\nOutline color ffd700\nFill color ff0000\n");

		circle.PrintInfo(issOut);
		CHECK(issOut.str() == issOutCheck.str());

		CHECK(circle.GetFillColor() == "ff0000");
		CHECK(circle.GetOutlineColor() == "ffd700");
	}

	SECTION("CLineSegment")
	{
		CPoint startPoint(0.0, 15.0);
		CPoint endPoint(15.0, 7.0);
		std::string outlineColor = "ffd700";
		CLineSegment line(startPoint, endPoint, outlineColor);

		CHECK(line.GetArea() == 0.0);
		CHECK(line.GetPerimeter() == 17.0);
		CHECK(line.GetStartPoint().GetX() == startPoint.GetX());
		CHECK(line.GetStartPoint().GetY() == startPoint.GetY());

		std::stringstream issOut;
		std::stringstream issOutCheck("line\nArea 0\nPerimeter 17\nStart point 0 15\nEnd point 15 7\nOutline color ffd700\n");

		line.PrintInfo(issOut);
		CHECK(issOut.str() == issOutCheck.str());

		CHECK(line.GetEndPoint().GetX() == endPoint.GetX());
		CHECK(line.GetEndPoint().GetY() == endPoint.GetY());

		CHECK(line.GetOutlineColor() == "ffd700");
	}
}

TEST_CASE("ShapeController")
{
	SECTION("CRectangle")
	{
		std::stringstream issIn("rectangle 10.3 20.15 30.7 40.4 ff0000 00ff00");
		std::stringstream issOut;

		CShapeController shapeController(issIn, issOut);

		shapeController.ProcessingCommand();
		shapeController.PrintShapeInfo();

		std::stringstream issOutCheck("rectangle\nArea 1240.28\nPerimeter 142.2\nLeft top 10.3 20.15\nRight bottom 41 60.55\nWidth 30.7\nHeight 40.4\nOutline color ff0000\nFill color 00ff00\n");

		CHECK(issOut.str() == issOutCheck.str());
	}

	SECTION("CTriangle")
	{
		std::stringstream issIn("triangle 0 0 -6 0 -5 8 940c0c ad9e9e");
		std::stringstream issOut;

		CShapeController shapeController(issIn, issOut);

		shapeController.ProcessingCommand();
		shapeController.PrintShapeInfo();

		std::stringstream issOutCheck("triangle\nArea 24\nPerimeter 23.4962\nVertex1 0 0\nVertex2 -6 0\nVertex3 -5 8\nOutline color 940c0c\nFill color ad9e9e\n");

		CHECK(issOut.str() == issOutCheck.str());
	}

	SECTION("CCircle")
	{
		std::stringstream issIn("circle 0 150 69.17 e04f4f 290707");
		std::stringstream issOut;

		CShapeController shapeController(issIn, issOut);

		shapeController.ProcessingCommand();
		shapeController.PrintShapeInfo();

		std::stringstream issOutCheck("circle\nArea 15023.3\nPerimeter 434.388\nCenter 0 150\nRadius 69.17\nOutline color e04f4f\nFill color 290707\n");

		CHECK(issOut.str() == issOutCheck.str());
	}

	SECTION("CLineSegment")
	{
		std::stringstream issIn("line 0 15 88 120 704141");
		std::stringstream issOut;

		CShapeController shapeController(issIn, issOut);

		shapeController.ProcessingCommand();
		shapeController.PrintShapeInfo();

		std::stringstream issOutCheck("line\nArea 0\nPerimeter 137\nStart point 0 15\nEnd point 88 120\nOutline color 704141\n");

		CHECK(issOut.str() == issOutCheck.str());
	}

	SECTION("Unknown figure")
	{
		std::stringstream issIn("hello 0 15 88 120 704141");
		std::stringstream issOut;

		CShapeController shapeController(issIn, issOut);

		shapeController.ProcessingCommand();
		shapeController.PrintShapeInfo();

		std::stringstream issOutCheck("Unknown figure\nYou have not created a shape\n");

		CHECK(issOut.str() == issOutCheck.str());
	}

	SECTION("Empty input")
	{
		std::stringstream issIn("");
		std::stringstream issOut;

		CShapeController shapeController(issIn, issOut);

		shapeController.ProcessingCommand();
		shapeController.PrintShapeInfo();

		std::stringstream issOutCheck("You have not created a shape\n");

		CHECK(issOut.str() == issOutCheck.str());
	}

	SECTION("PrintShapeInfo")
	{
		std::stringstream issIn("line 10 14 35 10 c24444\nrectangle 0 0 30 10 300b0b 1f1717\ncircle 46.9 35.1 18.9 249fa6 719407\ntriangle 53 33.9 12 39 40 75.1 0a3304 330404");
		std::stringstream issOut;

		CShapeController shapeController(issIn, issOut);

		shapeController.ProcessingCommand();
		shapeController.PrintShapeInfo();

		std::stringstream issOutCheck("The figure with the maximum area: circle\nArea 1121.64\nPerimeter 118.692\nCenter 46.9 35.1\nRadius 18.9\nOutline color 249fa6\nFill color 719407\n\nThe figure with the minimum perimeter: line\nArea 0\nPerimeter 25.318\nStart point 10 14\nEnd point 35 10\nOutline color c24444\n");

		CHECK(issOut.str() == issOutCheck.str());
	}
}
