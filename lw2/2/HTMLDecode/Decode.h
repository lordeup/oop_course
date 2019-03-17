#pragma once

#include <string>

const char START_DECODE = '&';
const char END_DECODE = ';';

struct HtmlDecoder
{
	std::string code;
	char symbol;
};

const HtmlDecoder QUOTES = { "&quot;", '"' };
const HtmlDecoder APOSTROPHE = { "&apos;", '\'' };
const HtmlDecoder LESS_TOKEN = { "&lt;", '<' };
const HtmlDecoder GREATER_TOKEN = { "&gt;", '>' };
const HtmlDecoder AMPERSAND = { "&amp;", '&' };

char GetCharacter(std::string const& strElement);
std::string HtmlDecode(std::string const& html);