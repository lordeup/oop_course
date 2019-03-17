#include "pch.h"
#include "../../2/HTMLDecode/Decode.h"

TEST_CASE("GetCharacter")
{
	CHECK(GetCharacter(QUOTES.code) == QUOTES.symbol);
	CHECK(GetCharacter(APOSTROPHE.code) == APOSTROPHE.symbol);
	CHECK(GetCharacter(LESS_TOKEN.code) == LESS_TOKEN.symbol);
	CHECK(GetCharacter(GREATER_TOKEN.code) == GREATER_TOKEN.symbol);
	CHECK(GetCharacter(AMPERSAND.code) == AMPERSAND.symbol);
	CHECK(GetCharacter("Hello") == ' ');
}

TEST_CASE("HtmlDecode test cat")
{
	std::string strIn = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	std::string strOut = "Cat <says> \"Meow\". M&M's";
	CHECK(HtmlDecode(strIn) == strOut);
}

TEST_CASE("HtmlDecode test1 html")
{
	std::string strIn = "&lt;!DOCTYPE html&gt;";
	std::string strOut = "<!DOCTYPE html>";
	CHECK(HtmlDecode(strIn) == strOut);
}

TEST_CASE("HtmlDecode test2 html")
{
	std::string strIn = "&lt;meta http-equiv = &quot;Content-Type&quot; content = &quot;text/html&quot;&gt;";
	std::string strOut = "<meta http-equiv = \"Content-Type\" content = \"text/html\">";
	CHECK(HtmlDecode(strIn) == strOut);
}