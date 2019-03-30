#define CATCH_CONFIG_MAIN
#include "../../3/CountingWords/Process.h"
#include <catch2/catch.hpp>

TEST_CASE("CountWord test empty string")
{
	std::string str = "";
	WordFrequency outMap = {};
	CHECK(CountWord(str) == outMap);
}

TEST_CASE("CountWord test string with space")
{
	std::string str = "       ";
	WordFrequency outMap = {};
	CHECK(CountWord(str) == outMap);
}

TEST_CASE("CountWord test one words")
{
	std::string str = "HEllo";
	WordFrequency outMap = { { "hello", 1 } };
	CHECK(CountWord(str) == outMap);
}

TEST_CASE("CountWord test repeat words")
{
	std::string str = "WORLD world WORLd";
	WordFrequency outMap = { { "world", 3 } };
	CHECK(CountWord(str) == outMap);
}

TEST_CASE("CountWord test long string")
{
	std::string str = "But I must EXPLAIN of AND denouncing pleasure and";
	WordFrequency outMap = { { "and", 2 }, { "but", 1 }, { "denouncing", 1 }, { "explain", 1 }, { "i", 1 }, { "must", 1 }, { "of", 1 }, { "pleasure", 1 } };
	CHECK(CountWord(str) == outMap);
}
