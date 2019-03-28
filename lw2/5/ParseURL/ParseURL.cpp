#include "pch.h"
#include "ParseURL.h"

std::string ToUpperCase(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), toupper);
	return str;
}

bool GetProtocol(const std::string& strProtocol, Protocol& protocol)
{
	if (ToUpperCase(strProtocol) == HTTP)
	{
		protocol = Protocol::HTTP;
		return true;
	}
	if (ToUpperCase(strProtocol) == HTTPS)
	{
		protocol = Protocol::HTTPS;
		return true;
	}
	if (ToUpperCase(strProtocol) == FTP)
	{
		protocol = Protocol::FTP;
		return true;
	}
	return false;
}

int GetPort(const Protocol& protocol)
{
	if (protocol == Protocol::HTTP)
	{
		return HTTP_PORT;
	}
	if (protocol == Protocol::HTTPS)
	{
		return HTTPS_PORT;
	}
	if (protocol == Protocol::FTP)
	{
		return FTP_PORT;
	}
	return -1;
}

bool ParseURL(std::string const& url, Protocol& protocol, int& port, std::string& host, std::string& document)
{
	std::regex strRegex("(http|HTTP|https|HTTPS|ftp|FTP)://([[:alnum:]-\\.]+):([\\d]+)/([\\S]*)");
	std::regex strRegexPortDefault("(http|HTTP|https|HTTPS|ftp|FTP)://([[:alnum:]-\\.]+)/([\\S]*)");
	std::smatch match;

	if (regex_match(url, match, strRegex))
	{
		if (!GetProtocol(match.str(1), protocol))
		{
			return false;
		}
		host = match.str(2);

		port = std::stoi(match.str(3));
		if (port < MIN_NUMBER_PORT || port > MAX_NUMBER_PORT)
		{
			return false;
		}

		document = match.str(4);

		return true;
	}

	if (regex_match(url, match, strRegexPortDefault))
	{
		if (!GetProtocol(match.str(1), protocol))
		{
			return false;
		}

		host = match.str(2);
		port = GetPort(protocol);
		document = match.str(3);

		return true;
	}

	return false;
}
