#include "pch.h"
#include "ParseURL.h"
#include <iostream>

int main()
{
	Protocol protocol;
	std::string url;
	std::string host;
	std::string document;
	int port;

	while (getline(std::cin, url))
	{
		if (ParseURL(url, protocol, port, host, document))
		{
			std::cout << url << std::endl;
			std::cout << HOST << host << std::endl;
			std::cout << PORT << port << std::endl;
			std::cout << DOC << document << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cerr << INPUT_ERROR << std::endl;
			std::cout << std::endl;
		}
	}

	return 0;
}
