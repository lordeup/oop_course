#pragma once
#include <string>

const int HTTP_PORT = 80;
const int HTTPS_PORT = 443;

const int MIN_NUMBER_PORT = 1;
const int MAX_NUMBER_PORT = 65535;

const int MATCH_PROTOCOL_URL = 1;
const int MATCH_DOMAIN_URL = 2;
const int MATCH_PORT_URL = 3;
const int MATCH_DOCUMENT_URL = 4;

const std::string URL_REGULAR_EXPRESSION = R"((http|HTTP|https|HTTPS)://([[:alnum:]-\\.]+)(?:\:([[:digit:]]+))?(?:\/(\S*))?$)";
const std::string DOMAIN_REGULAR_EXPRESSION = R"(^([[:alnum:]-\\.]+)$)";

const std::string HTTP_STRING = "http";
const std::string HTTPS_STRING = "https";

const std::string URL_INPUT_ERROR = "Invalid URL input";
const std::string URL_PORT_ERROR = "Invalid URL port";
const std::string URL_DOMAIN_ERROR = "Invalid URL domain";
const std::string URL_DOCUMENT_ERROR = "Invalid URL document";
const std::string URL_PROTOCOL_UNKNOWN_ERROR = "Unknown Protocol type";
const std::string URL_EMPTY_ERROR = "Url is empty";

const std::string SLASH_STRING = "/";
const char SLASH_CHAR = '/';

const std::string URL = "URL: ";
const std::string PROTOCOL_URL = "PROTOCOL: ";
const std::string DOMAIN_URL = "DOMAIN: ";
const std::string PORT_URL = "PORT: ";
const std::string DOCUMENT_URL = "DOCUMENT: ";
