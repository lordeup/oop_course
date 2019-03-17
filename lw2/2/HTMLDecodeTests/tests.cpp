#include "pch.h"
#include "lw2/2/HTMLDecode/Decode.h"

TEST_CASE("GetCharacter")
{
	CHECK(GetCharacter(QUOTES) == '"');
	CHECK(GetCharacter(APOSTROPHE) == '\'');
	CHECK(GetCharacter(LESS_TOKEN) == '<');
	CHECK(GetCharacter(GREATER_TOKEN) == '>');
	CHECK(GetCharacter(AMPERSAND) == '&');
	CHECK(GetCharacter("Hello") == ' ');
}