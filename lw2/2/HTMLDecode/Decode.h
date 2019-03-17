#pragma once

#include <string>

const char START_DECODE = '&';
const char END_DECODE = ';';

const std::string QUOTES = "&quot;";
const std::string APOSTROPHE = "&apos;";
const std::string LESS_TOKEN = "&lt;";
const std::string GREATER_TOKEN = "&gt;";
const std::string AMPERSAND = "&amp;";

char GetCharacter(std::string const& strElement);
std::string HtmlDecode(std::string const& html);