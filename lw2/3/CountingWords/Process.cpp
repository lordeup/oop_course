#include "pch.h"
#include "Process.h"

WordFrequency CountWord(std::string& str)
{
	WordFrequency word;
	std::istringstream iss(str);

	while (iss >> str)
	{
		std::transform(str.begin(), str.end(), str.begin(), tolower);
		++word[str];
	}

	return word;
}
