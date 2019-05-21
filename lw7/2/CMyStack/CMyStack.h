#pragma once
#include <memory>
#include "Const.h"

template <typename T>
class CMyStack
{
public:
	CMyStack();
	~CMyStack();
	void Push(T const& t);
	T GetTop() const;

	void Pop();
	void Clear();
	bool IsEmpty() const;

private:
	struct Node
	{
		Node(T const& value, std::shared_ptr<Node> const& nextNode)
			: data(value)
			, prev(nextNode)
		{
		}

		T data;
		std::shared_ptr<Node> prev = nullptr;
	};

	unsigned m_size;
	std::shared_ptr<Node> m_top;
};

template <typename T>
CMyStack<T>::CMyStack::CMyStack()
	: m_size(0)
	, m_top(nullptr)
{
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