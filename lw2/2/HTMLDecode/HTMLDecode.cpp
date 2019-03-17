#include "pch.h"
#include <iostream>
#include "Decode.h"

int main()
{
	std::string str;
	while (std::getline(std::cin, str))
	{
		std::string decodedString = HtmlDecode(str);
		std::cout << decodedString << std::endl;
	}
}