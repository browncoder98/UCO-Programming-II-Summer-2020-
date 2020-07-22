#include <iostream>
#include <cassert>
using namespace std;
#include "nstack.h"

nstack::node::node(int d)
	: data(d), link(nullptr)
{
}

nstack::nstack() : ptop(nullptr)
{
}

nstack::~nstack()
{
	while (!empty())
	{
		pop();
	}
}

void nstack::push(int data)
{
	node *new_node = new node(data);

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

void nstack::pop()
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
		node *discard = ptop;
		ptop = ptop->link; // bypass top of the stack
		delete discard;
	}
}

bool nstack::empty() const
{
	return ptop == nullptr;
}

bool nstack::full() const
{
	return false;
}

int nstack::top() const
{
	assert(!empty());
	return ptop->data;
}