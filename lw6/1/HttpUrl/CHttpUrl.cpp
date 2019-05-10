#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <regex>

CHttpUrl::CHttpUrl(std::string const& url)
{
	if (url.empty())
	{
		throw CUrlParsingError(URL_EMPTY_ERROR);
	}

	std::regex strRegex(R"((http|HTTP|https|HTTPS)://([[:alnum:]-\\.]+)(?::([0-9]+))?(?:\/(.*))?$)");

	std::smatch match;

	if (!regex_match(url, match, strRegex))
	{
		throw CUrlParsingError(URL_INPUT_ERROR);
	}

	m_protocol = ValidProtocol(match.str(1));
	m_domain = ValidDomain(match.str(2));

	if (!match.str(3).empty())
	{
		m_port = ValidPort(match.str(3));
	}
	else
	{
		m_port = GetDefaultPort(m_protocol);
	}

	m_document = ValidDocument(match.str(4));
	m_url = url;
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol = HTTP)
	: m_domain(ValidDomain(domain))
	, m_document(ValidDocument(document))
	, m_protocol(protocol)
{
	m_port = GetDefaultPort(protocol);
	m_url = GetProtocolString() + "://" + m_domain + m_document;
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, int port)
	: m_domain(ValidDomain(domain))
	, m_document(ValidDocument(document))
	, m_protocol(protocol)
{
	if (port < MIN_NUMBER_PORT || port > MAX_NUMBER_PORT)
	{
		throw CUrlParsingError(URL_PORT_ERROR);
	}

	m_port = port;
	m_url = GetProtocolString() + "://" + m_domain + ":" + std::to_string(m_port) + m_document;
}

Protocol CHttpUrl::ValidProtocol(const std::string& strProtocol)
{
	if (ToLowerCase(strProtocol) == HTTPS_STRING)
	{
		return Protocol::HTTPS;
	}
	else if (ToLowerCase(strProtocol) == HTTP_STRING)
	{
		return Protocol::HTTP;
	}
	else
	{
		throw CUrlParsingError(URL_PROTOCOL_UNKNOWN_ERROR);
	}
}

std::string CHttpUrl::ValidDomain(const std::string& strDomain)
{
	std::regex regex(R"(^([[:alnum:]-\\.]+)$)");
	std::smatch match;
	if (!regex_match(strDomain, match, regex))
	{
		throw CUrlParsingError(URL_DOMAIN_ERROR);
	}

	return strDomain;
}

int CHttpUrl::ValidPort(const std::string& strPort)
{
	int port = std::stoi(strPort);
	if (port < MIN_NUMBER_PORT || port > MAX_NUMBER_PORT)
	{
		throw CUrlParsingError(URL_PORT_ERROR);
	}
	else
	{
		return port;
	}
}

int CHttpUrl::GetDefaultPort(Protocol protocol)
{
	switch (protocol)
	{
	case HTTP:
		return HTTP_PORT;
	case HTTPS:
		return HTTPS_PORT;
	default:
		throw CUrlParsingError(URL_PROTOCOL_UNKNOWN_ERROR);
	}
}

std::string CHttpUrl::ValidDocument(const std::string& strDocument)
{
	if (strDocument.empty())
	{
		return SLASH_STRING;
	}
	else if (strDocument[0] == SLASH_CHAR)
	{
		return strDocument;
	}
	else
	{
		return SLASH_STRING + strDocument;
	}
}

std::string CHttpUrl::ToLowerCase(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), tolower);
	return str;
}

std::string CHttpUrl::GetURL() const
{
	return m_url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

std::string CHttpUrl::GetProtocolString() const
{
	switch (m_protocol)
	{
	case HTTP:
		return HTTP_STRING;
	case HTTPS:
		return HTTPS_STRING;
	default:
		throw CUrlParsingError(URL_PROTOCOL_UNKNOWN_ERROR);
	}
}

int CHttpUrl::GetPort() const
{
	return m_port;
}
