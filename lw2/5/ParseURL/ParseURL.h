#pragma once

#include <regex>
#include <string>

const int HTTP_PORT = 80;
const int HTTPS_PORT = 243;
const int FTP_PORT = 21;

const int MIN_NUMBER_PORT = 1;
const int MAX_NUMBER_PORT = 65535;

const std::string HOST = "HOST: ";
const std::string PORT = "PORT: ";
const std::string DOC = "DOC: ";

const std::string HTTP = "HTTP";
const std::string HTTPS = "HTTPS";
const std::string FTP = "FTP";

const std::string INPUT_ERROR = "Invalid URL input";

enum class Protocol
{
	HTTP,
	HTTPS,
	FTP
};

std::string ToUpperCase(std::string str);
bool GetProtocol(const std::string& strProtocol, Protocol& protocol);
int GetPort(const Protocol& protocol);
bool ParseURL(std::string const& url, Protocol& protocol, int& port, std::string& host, std::string& document);