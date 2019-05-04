#include "CHttpUrl.h"

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetURL() const
{
	return m_url;
}