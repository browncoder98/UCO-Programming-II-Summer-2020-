#include "listiterator.h"
#include <cassert>
#include <iostream>
using namespace std;

listiterator::listiterator()
	: pos(nullptr), container(nullptr)
{
}

int listiterator::get() const
{
	assert(pos != nullptr);
	return pos->data;
}

void listiterator::next()
{
	assert(pos != nullptr);
	pos = pos->next;
}

void listiterator::prev()
{
	if (pos == nullptr)
	{
		//if pos is past the tail
		pos = container->tail;
	}
	else
	{
		pos = pos->prev;
	}
}

bool listiterator::equals(listiterator iter) const
{
	return pos == iter.pos;
}
