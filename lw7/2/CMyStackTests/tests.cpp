#define CATCH_CONFIG_MAIN
#include "../../2/CMyStack/CMyStack.h"
#include <catch2/catch.hpp>
#include <string>

TEST_CASE("int")
{
	CMyStack<int> stack;

	SECTION("one element")
	{
		stack.Push(99);
		CHECK(stack.GetTop() == 99);

		stack.Pop();
		CHECK_THROWS_AS(stack.GetTop(), std::logic_error);
		CHECK(stack.IsEmpty() == true);
	}

	SECTION("not empty")
	{
		stack.Push(1);
		stack.Push(2);
		stack.Push(3);
		stack.Push(4);

		CHECK(stack.IsEmpty() == false);

		stack.Pop();
		CHECK(stack.GetTop() == 3);

		stack.Pop();
		CHECK(stack.GetTop() == 2);

		stack.Pop();
		CHECK(stack.GetTop() == 1);

		stack.Pop();
		CHECK_THROWS_AS(stack.GetTop(), std::logic_error);
		CHECK(stack.IsEmpty() == true);
	}

	SECTION("empty")
	{
		CHECK(stack.IsEmpty() == true);
	}

	SECTION("Clear")
	{
		stack.Push(1);
		stack.Push(2);
		stack.Push(3);
		stack.Push(4);

		CHECK(stack.IsEmpty() == false);

		stack.Clear();
		CHECK(stack.IsEmpty() == true);
	}
}

TEST_CASE("string")
{
	CMyStack<std::string> stack;

	SECTION("one element")
	{
		stack.Push("hello");
		CHECK(stack.GetTop() == "hello");

		stack.Pop();
		CHECK_THROWS_AS(stack.GetTop(), std::logic_error);
		CHECK(stack.IsEmpty() == true);
	}

	SECTION("not empty")
	{
		stack.Push("Hello");
		stack.Push("World");
		stack.Push("How");
		stack.Push("Are");
		stack.Push("You");

		CHECK(stack.IsEmpty() == false);

		stack.Pop();
		CHECK(stack.GetTop() == "Are");

		stack.Pop();
		CHECK(stack.GetTop() == "How");

		stack.Pop();
		CHECK(stack.GetTop() == "World");

		stack.Pop();
		CHECK(stack.GetTop() == "Hello");

		stack.Pop();
		CHECK_THROWS_AS(stack.GetTop(), std::logic_error);
		CHECK(stack.IsEmpty() == true);
	}

	SECTION("empty")
	{
		CHECK(stack.IsEmpty() == true);
	}

	SECTION("Clear")
	{
		stack.Push("Hello");
		stack.Push("World");
		stack.Push("How");
		stack.Push("Are");
		stack.Push("You");

		CHECK(stack.IsEmpty() == false);

		stack.Clear();
		CHECK(stack.IsEmpty() == true);
	}
}