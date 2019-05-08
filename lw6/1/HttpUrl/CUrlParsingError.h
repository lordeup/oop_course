#pragma once
#include <string>
#include <stdexcept>

class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(const std::string& error_message);
	std::string GetErrorMessage() const;

private:
	std::string m_error_message;
};