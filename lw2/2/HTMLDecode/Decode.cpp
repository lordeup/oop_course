#include "pch.h"
#include "Decode.h"

char GetCharacter(std::string const& strElement)
{
	if (strElement == QUOTES)
	{
		return '"';
	}
	else if (strElement == APOSTROPHE)
	{
		return '\'';
	}
	else if (strElement == LESS_TOKEN)
	{
		return '<';
	}
	else if (strElement == GREATER_TOKEN)
	{
		return '>';
	}
	else if (strElement == AMPERSAND)
	{
		return '&';
	}
	else
	{
		return ' ';
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
