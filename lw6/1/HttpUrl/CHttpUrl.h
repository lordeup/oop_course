#pragma once
#include "Const.h"

enum Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);
	CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, int port);

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	std::string GetProtocolString() const;
	Protocol GetProtocol() const;
	int GetPort() const;

private:
	std::string m_url;
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	int m_port;

	std::string ToLowerCase(std::string str);
	int GetDefaultPort(Protocol protocol);

	int ValidPort(const std::string& strPort);
	std::string ValidDomain(const std::string& strDomain);
	std::string ValidDocument(const std::string& strDocument);

	Protocol ValidProtocol(const std::string& strProtocol);
};
