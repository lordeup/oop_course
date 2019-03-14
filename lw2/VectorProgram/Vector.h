#pragma once

#include "ProcessVector.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

const int ROUNDING_FACTOR = 3;
const std::string ERROR_VALUE_NUMBER = "Invalid input";

bool FillVector(vecNumber& numbers);
void PrintVector(vecNumber& numbers);
