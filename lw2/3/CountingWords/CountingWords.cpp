#include "pch.h"
#include "Process.h"
#include <sstream>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Word word;

	std::string str;
	std::getline(std::cin, str);
	std::istringstream iss(str);

	while (iss >> str)
	{
		CountWord(word, str);
	}

	PrintCountWord(word);

	return 0;
}
