#include "pch.h"
#include "Process.h"
#include <iostream>
#include <Windows.h>

void PrintCountWord(WordFrequency& word)
{
	for (auto s : word)
	{
		std::cout << s.first << " -> " << s.second << std::endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	std::string str;
	std::getline(std::cin, str);

	WordFrequency word = CountWord(str);

	PrintCountWord(word);

	return 0;
}
