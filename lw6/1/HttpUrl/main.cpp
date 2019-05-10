#include "pch.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <iostream>

int main()
{
	std::string urlStr;

	while (getline(std::cin, urlStr))
	{
		try
		{
			CHttpUrl url(urlStr);

			std::cout << URL << url.GetURL() << std::endl;
			std::cout << PROTOCOL_URL << url.GetProtocolString() << std::endl;
			std::cout << DOMAIN_URL << url.GetDomain() << std::endl;
			std::cout << PORT_URL << url.GetPort() << std::endl;
			std::cout << DOCUMENT_URL << url.GetDocument() << std::endl;
		}
		catch (const CUrlParsingError& err)
		{
			std::cout << err.what() << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}
