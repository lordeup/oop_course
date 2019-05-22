#define CATCH_CONFIG_MAIN
#include "../../2/CMyStack/CMyStack.h"
#include <catch2/catch.hpp>
#include <string>

TEST_CASE("int")
{
	CMyStack<int> stack;
	CMyStack<int> copyStack;

	SECTION("One element")
	{
		stack.Push(99);
		CHECK(stack.GetTop() == 99);

		stack.Pop();
		CHECK_THROWS_AS(stack.GetTop(), std::logic_error);
		CHECK(stack.IsEmpty() == true);
	}

	SECTION("Empty")
	{
		CHECK(stack.IsEmpty() == true);
	}

	SECTION("Not empty")
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

	SECTION("CopyStack")
	{
		stack.Push(1);
		stack.Push(2);

		CMyStack<int> stack2(stack);

		CHECK(stack2.IsEmpty() == false);

		CHECK(stack.GetTop() == stack2.GetTop());
	}

	SECTION("CopyStack operator =")
	{
		stack.Push(1);
		stack.Push(2);
		copyStack.Push(1);
		copyStack.Push(2);
		copyStack.Push(3);
		copyStack.Push(4);

		copyStack = stack;

		CHECK(stack.GetTop() == copyStack.GetTop());
		copyStack.Pop();
		CHECK(stack.GetTop() != copyStack.GetTop());
		CHECK(copyStack.GetTop() == 1);
	}

	SECTION("Self-assignment CopyStack operator =")
	{
		CMyStack<int> copyStack;

		stack.Push(1);
		stack.Push(2);

		stack = stack;

		CHECK_THROWS_AS(copyStack.GetTop(), std::logic_error);
		CHECK(copyStack.IsEmpty() == true);
		CHECK(stack.GetTop() == 2);
	}
}

TEST_CASE("string")
{
	CMyStack<std::string> stack;
	CMyStack<std::string> copyStack;

	SECTION("One element")
	{
		stack.Push("hello");
		CHECK(stack.GetTop() == "hello");

		stack.Pop();
		CHECK_THROWS_AS(stack.GetTop(), std::logic_error);
		CHECK(stack.IsEmpty() == true);
	}

	SECTION("Not empty")
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

	SECTION("Empty")
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

	SECTION("CopyStack")
	{
		stack.Push("Hello");
		stack.Push("World");

		CMyStack<std::string> stack2(stack);

		CHECK(stack2.IsEmpty() == false);

		CHECK(stack.GetTop() == stack2.GetTop());
	}

	SECTION("CopyStack operator =")
	{
		stack.Push("Hello");
		stack.Push("World");
		copyStack.Push("Hello");
		copyStack.Push("World");
		copyStack.Push("How");
		copyStack.Push("Are");

		copyStack = stack;

		CHECK(stack.GetTop() == copyStack.GetTop());
		copyStack.Pop();
		CHECK(stack.GetTop() != copyStack.GetTop());
		CHECK(copyStack.GetTop() == "Hello");
	}

	SECTION("Self-assignment CopyStack operator =")
	{
		CMyStack<int> copyStack;

		stack.Push("Hello");
		stack.Push("World");

		stack = stack;

		CHECK_THROWS_AS(copyStack.GetTop(), std::logic_error);
		CHECK(copyStack.IsEmpty() == true);
		CHECK(stack.GetTop() == "World");
	}
}