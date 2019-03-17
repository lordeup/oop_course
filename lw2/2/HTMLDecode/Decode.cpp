#include "pch.h"
#include "Decode.h"

char GetCharacter(std::string const& strElement)
{
	char empty = ' ';
	if (strElement == QUOTES.code)
	{
		return QUOTES.symbol;
	}
	else if (strElement == APOSTROPHE.code)
	{
		return APOSTROPHE.symbol;
	}
	else if (strElement == LESS_TOKEN.code)
	{
		return LESS_TOKEN.symbol;
	}
	else if (strElement == GREATER_TOKEN.code)
	{
		return GREATER_TOKEN.symbol;
	}
	else if (strElement == AMPERSAND.code)
	{
		return AMPERSAND.symbol;
	}
	else
	{
		return empty;
	}
}

std::string HtmlDecode(std::string const& html)
{
	std::string resultStr;
	int shift;

	for (auto it = html.begin(); it != html.end(); it += shift)
	{
		shift = 1;
		if ((*it) != START_DECODE)
		{
			resultStr += (*it);
		}
		else
		{
			shift = std::find(it, html.end(), END_DECODE) - it + 1;
			std::string strSub = html.substr((it - html.begin()), shift);
			resultStr += GetCharacter(strSub);
		}
	}

	return resultStr;
}
