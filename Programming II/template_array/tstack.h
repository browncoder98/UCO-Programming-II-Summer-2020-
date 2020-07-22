#pragma once
#include <iostream>
#include <cassert>
using namespace std;

#include "tnode.h"

template <typename T>

class tstack
{
private:
	tnode<T> *ptop;

public:
	tstack();
	~tstack();
	void push(T);
	void pop();
	T top() const;
	bool empty() const;
	bool full() const;
};

template <typename T>
tstack<T>::tstack() : ptop(nullptr)
{
}

template <typename T>
tstack<T>::~tstack()
{
	while (!empty())
	{
		pop();
	}
}

template <typename T>
void tstack<T>::push(T data)
{
	tnode<T> *new_node = new tnode<T>(data);

	if (ptop == nullptr)
	{
		ptop = new_node;
	}
	else
	{
		new_node->link = ptop;
		ptop = new_node;
	}
}

template <typename T>
void tstack<T>::pop()
{
	assert(!empty());

	if (ptop->link == nullptr)
	{
		//one node only
		delete ptop;
		ptop = nullptr;
	}
	else
	{
		tnode<T> *discard = ptop;
		ptop = ptop->link; // bypass top of the stack
		delete discard;
	}
}

template <typename T>
bool tstack<T>::empty() const
{
	return ptop == nullptr;
}

template <typename T>
bool tstack<T>::full() const
{
	return false;
}

template <typename T>
T tstack<T>::top() const
{
	assert(!empty());
	return ptop->data;
}
