#pragma once
#include "Const.h"
#include <memory>

template <typename T>
class CMyStack
{
public:
	CMyStack();
	CMyStack(const CMyStack& copyOtherStack);
	~CMyStack();
	void Push(T const& t);
	T GetTop() const;

	void Pop();
	void Clear();
	bool IsEmpty() const;

	CMyStack<T>& operator=(CMyStack<T> const& copyOtherStack);

private:
	struct Node
	{
		Node(T const& value, std::shared_ptr<Node> const& node)
			: data(value)
			, prev(node)
		{
		}

		T data;
		std::shared_ptr<Node> prev = nullptr;
	};

	typedef std::shared_ptr<Node> NodePtr;

	unsigned m_size;
	NodePtr m_top;
};

template <typename T>
CMyStack<T>::CMyStack::CMyStack()
	: m_size(0)
	, m_top(nullptr)
{
}

template <typename T>
CMyStack<T>::CMyStack::CMyStack(const CMyStack& copyOtherStack)
{
	if (!copyOtherStack.IsEmpty())
	{
		m_size = copyOtherStack.m_size;

		NodePtr currentPtr = copyOtherStack.m_top;

		NodePtr previousPtr = std::make_shared<Node>(currentPtr->data, nullptr);
		m_top = previousPtr;

		while (currentPtr != nullptr)
		{
			NodePtr newPtr = std::make_shared<Node>(currentPtr->data, nullptr);
			previousPtr->prev = newPtr;
			currentPtr = currentPtr->prev;
		}
	}
}

template <typename T>
CMyStack<T>::CMyStack::~CMyStack()
{
	Clear();
}

template <typename T>
void CMyStack<T>::Push(T const& t)
{
	m_top = std::make_shared<Node>(t, m_top);
	++m_size;
}

template <typename T>
T CMyStack<T>::GetTop() const
{
	if (IsEmpty())
	{
		throw std::logic_error(STACK_EMPTY_ERROR);
	}
	return m_top->data;
}

template <typename T>
void CMyStack<T>::Pop()
{
	if (!IsEmpty())
	{
		m_top->data.~T();
		m_top = m_top->prev;
		--m_size;
	}
}

template <typename T>
void CMyStack<T>::Clear()
{
	while (!IsEmpty())
	{
		Pop();
	}
}

template <typename T>
bool CMyStack<T>::IsEmpty() const
{
	return (m_size == 0) ? true : false;
}

template <typename T>
CMyStack<T>& CMyStack<T>::operator=(CMyStack<T> const& copyOtherStack)
{
	if (this == &copyOtherStack)
	{
		return *this;
	}

	if (!copyOtherStack.IsEmpty())
	{
		Clear();
		m_size = copyOtherStack.m_size;

		NodePtr currentPtr = copyOtherStack.m_top;

		NodePtr previousPtr = std::make_shared<Node>(currentPtr->data, nullptr);
		m_top = previousPtr;

		while (currentPtr != nullptr)
		{
			NodePtr newPtr = std::make_shared<Node>(currentPtr->data, nullptr);
			previousPtr->prev = newPtr;
			currentPtr = currentPtr->prev;
		}
	}

	return *this;
}