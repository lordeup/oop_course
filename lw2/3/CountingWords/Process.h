#pragma once

#include <algorithm>
#include <map>
#include <sstream>
#include <string>

typedef std::map<std::string, int> WordFrequency;

WordFrequency CountWord(std::string& str);
