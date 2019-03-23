#include "pch.h"
#include "Decode.h"


std::string GetCharacter(std::string const& strElement)
{
	std::string empty;
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
		if (*it == START_DECODE)
		{
			if (*(it + 1) == START_DECODE)
			{
				resultStr += (*it);
			}
			else
			{
				shift = std::find(it, html.end(), END_DECODE) - it + 1;
				std::string strSub = html.substr((it - html.begin()), shift);
				std::string str = GetCharacter(strSub);
				if (str != "")
				{
					resultStr += str;
				}
				else
				{
					resultStr += (*it);
					shift = 1;
				}
			}
		}
		else
		{
			resultStr += (*it);
		}
	}
	return resultStr;
}
