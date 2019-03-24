#include "pch.h"
#include "Process.h"


Word CountWord(Word& word, std::string& str)
{
	std::string strResult;
	for (size_t i = 0; i < str.length(); ++i)
	{
		std::transform(str.begin(), str.end(), str.begin(), tolower);
		strResult += str[i];
	}
	if (strResult.length() > 0)
	{
		++word[strResult];
	}
	return word;
}

void PrintCountWord(Word& word)
{
	for (auto s : word)
	{
		std::cout << s.first << " -> " << s.second << std::endl;
	}
}
