#define CATCH_CONFIG_MAIN
#include "../../5/ParseURL/ParseURL.h"
#include <catch2/catch.hpp>

Protocol protocol;
int port;
std::string host;
std::string document;

TEST_CASE("ToUpperCase")
{
	SECTION("HTTP")
	{
		std::string str = "http";
		CHECK(ToUpperCase(str) == HTTP);
	}

	SECTION("HTTPS")
	{
		std::string str = "https";
		CHECK(ToUpperCase(str) == HTTPS);
	}

	SECTION("FTP")
	{
		std::string str = "FTP";
		CHECK(ToUpperCase(str) == FTP);
	}
}

TEST_CASE("GetProtocol")
{
	SECTION("HTTP")
	{
		std::string str = "http";
		CHECK(GetProtocol(str, protocol) == true);
	}

	SECTION("HTTPS")
	{
		std::string str = "https";
		CHECK(GetProtocol(str, protocol) == true);
	}

	SECTION("FTP")
	{
		std::string str = "FTP";
		CHECK(GetProtocol(str, protocol) == true);
	}

	SECTION("Invalid input")
	{
		std::string str = "hppt";
		CHECK(GetProtocol(str, protocol) == false);
	}
}

TEST_CASE("GetPort")
{
	SECTION("HTTP")
	{
		protocol = Protocol::HTTP;
		CHECK(GetPort(protocol) == HTTP_PORT);
	}

	SECTION("HTTPS")
	{
		protocol = Protocol::HTTPS;
		CHECK(GetPort(protocol) == HTTPS_PORT);
	}

	SECTION("FTP")
	{
		protocol = Protocol::FTP;
		CHECK(GetPort(protocol) == FTP_PORT);
	}
}

TEST_CASE("ParseURL")
{
	SECTION("Test port less MIN_NUMBER_PORT")
	{
		std::string url = "FTPP://www.mysite.com:0/docs/document1.html?page=30&lang=en#title";
		CHECK(ParseURL(url, protocol, port, host, document) == false);
	}

	SECTION("Test port more MAX_NUMBER_PORT")
	{
		std::string url = "https://www.google.com:65536/search?q=hello+world&oq=hello+world&aqs=chrome..69i57j0l5.8051j0j7&sourceid=chrome&ie=UTF-8";
		CHECK(ParseURL(url, protocol, port, host, document) == false);
	}

	SECTION("Test port installed HTTP port MIN_NUMBER_PORT")
	{
		std::string url = "HTTP://www.mysite-time.com:1/docs/document1.html?page=3450&lang=en#zero17";
		std::string hostOut = "www.mysite-time.com";
		std::string documentOut = "docs/document1.html?page=3450&lang=en#zero17";
		CHECK(ParseURL(url, protocol, port, host, document) == true);
		CHECK(port == 1);
		CHECK(host == hostOut);
		CHECK(document == documentOut);
	}

	SECTION("Test port installed HTTPS port MAX_NUMBER_PORT")
	{
		std::string url = "https://drive.google.com:65535/drive/folders/0B8c4dq91MwITUk1RU1ZwWjFsWUk";
		std::string hostOut = "drive.google.com";
		std::string documentOut = "drive/folders/0B8c4dq91MwITUk1RU1ZwWjFsWUk";
		CHECK(ParseURL(url, protocol, port, host, document) == true);
		CHECK(port == 65535);
		CHECK(host == hostOut);
		CHECK(document == documentOut);
	}

	SECTION("Test port default HTTPS")
	{
		std::string url = "https://moodle.volgatech.net/CookieAuth.dll?GetLogon?curl=Z2FauthZ2FldapZ2Fntlmsso_magic.phpZ3FsesskeyZ3DchI4BeAphf&reason=0&formdir=12";
		std::string hostOut = "moodle.volgatech.net";
		std::string documentOut = "CookieAuth.dll?GetLogon?curl=Z2FauthZ2FldapZ2Fntlmsso_magic.phpZ3FsesskeyZ3DchI4BeAphf&reason=0&formdir=12";
		CHECK(ParseURL(url, protocol, port, host, document) == true);
		CHECK(port == HTTPS_PORT);
		CHECK(host == hostOut);
		CHECK(document == documentOut);
	}

	SECTION("Test port default FTP")
	{
		std::string url = "FTP://www.mysite.com/docs/document1.html?page=30&lang=en#title";
		std::string hostOut = "www.mysite.com";
		std::string documentOut = "docs/document1.html?page=30&lang=en#title";
		CHECK(ParseURL(url, protocol, port, host, document) == true);
		CHECK(port == FTP_PORT);
		CHECK(host == hostOut);
		CHECK(document == documentOut);
	}

	SECTION("Test invalid Protocol")
	{
		std::string url = "FTPP://www.mysite.com:1725/docs/document1.html?page=30&lang=en#title";
		CHECK(ParseURL(url, protocol, port, host, document) == false);
	}

	SECTION("Test invalid Protocol port default")
	{
		std::string url = "httpss://www.youtube.com/feed/subscriptions";
		CHECK(ParseURL(url, protocol, port, host, document) == false);
	}
}
