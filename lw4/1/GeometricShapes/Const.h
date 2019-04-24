#pragma once
#include <sstream>
#include <string>

const int POWER_NUMBER = 2;
const int MULTIPLICATION_FACTOR = 2;
const int ROUNDING_FACTOR = 3;

const std::string ERROR_FILE_NOT_EXIST = "This file does not exist";
const std::string ERROR_NOT_ENOUGH_ARGUMENTS = "The number of arguments does not match the task condition\n"
											   "Input should look: GeometricShapes.exe <input file>\n";
const std::string ERROR_EMPTY_INPUT = "You have not created a shape";

const std::string FIGURE_RECTANGLE = "rectangle";
const std::string FIGURE_TRIANGLE = "triangle";
const std::string FIGURE_CIRCLE = "circle";
const std::string FIGURE_LINE = "line";
const std::string FIGURE_UNKNOWN = "Unknown figure\n";

const std::string PERIMETER_SHAPE = "Perimeter ";
const std::string AREA_SHAPE = "Area ";
const std::string OUTLINE_COLOR_SHAPE = "Outline color ";
const std::string FILL_COLOR_SHAPE = "Fill color ";
const std::string SPACE = " ";

const std::string START_POINT_LINE = "Start point ";
const std::string END_POINT_LINE = "End point ";

const std::string VERTEX_1_TRIANGLE = "Vertex1 ";
const std::string VERTEX_2_TRIANGLE = "Vertex2 ";
const std::string VERTEX_3_TRIANGLE = "Vertex3 ";

const std::string LEFT_TOP_RECTANGLE = "Left top ";
const std::string RIGHT_BOTTOM_RECTANGLE = "Right bottom ";
const std::string WIDTH_RECTANGLE = "Width ";
const std::string HEIGHT_RECTANGLE = "Height ";

const std::string CENTER_CIRCLE = "Center ";
const std::string RADIUS_CIRCLE = "Radius ";

const std::string MAX_AREA_SHAPE = "The figure with the maximum area: ";
const std::string MIN_PERIMETER_SHAPE = "The figure with the minimum perimeter: ";
