#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <iostream>

typedef std::map<std::string, int> Word;

Word CountWord(Word& word, std::string& str);
void PrintCountWord(Word& word);
