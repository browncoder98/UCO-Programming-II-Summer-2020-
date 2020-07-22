#include "deque.h"
#include <cassert>

using namespace std;

deque::deque()
	: pfront(nullptr), pback(nullptr), count(0)
{
}

deque::~deque()
{
	while (length() > 0)
	{
		pop_front();
	}
}

int deque::length() const
{
	return count;
}

void deque::push_back(int data)
{
	node *p = new node(data);
	if (count == 0)
	{
		pfront = pback = p;
	}
	else
	{
		pback->next = p;
		p->prev = pback;
		pback = p;
	}
	++count;
}

int deque::front() const
{
	assert(length() != 0);
	return pfront->data;
}

int deque::back() const
{
	assert(length() != 0);
	return pback->data;
}

void deque::push_front(int data)
{
	node *p = new node(data);
	if (count == 0)
	{
		pfront = pback = p;
	}
	else
	{
		pfront->prev = p;
		p->next = pfront;
		pfront = p;
	}
	++count;
}

void deque::pop_front()
{
	assert(length() != 0);
	if (count == 1)
	{
		delete pfront;
		pfront = pback = nullptr;
	}
	else
	{
		node *discard = pfront;
		pfront = pfront->next;
		pfront->prev = nullptr;
		delete discard;
	}
	--count;
}

void deque::pop_back()
{
	assert(length() != 0);
	if (count == 1)
	{
		delete pfront;
		pfront = pback = nullptr;
	}
	else
	{
		node *discard = pback;
		pback = pback->prev;
		pback->next = nullptr;
		delete discard;
	}
	--count;
}