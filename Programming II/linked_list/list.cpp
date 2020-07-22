#include "list.h"
#include <iostream>
#include <cassert>
using namespace std;

list::list()
	: head(nullptr), tail(nullptr), count(0)
{
}

list::~list()
{
	//free nodes
}

int list::size() const
{
	return count;
}

void list::push_front(int data)
{
	node *p = new node(data);
	if (count == 0)
	{
		head = tail = p;
	}
	else
	{
		p->next = head;
		head->prev = p;
		head = p;
	}
	++count;
}

void list::push_back(int data)
{
	node *p = new node(data);
	if (count == 0)
	{
		head = tail = p;
	}
	else
	{
		tail->next = p;
		p->prev = tail;
		tail = p;
	}
	++count;
}

void list::pop_back()
{
	assert(count > 0);
	if (count == 1)
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		node *discard = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete discard;
	}
	--count;
}

void list::pop_front()
{
	assert(count > 0);
	if (count == 1)
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		node *discard = head;
		head = head->next;
		head->prev = nullptr;
		delete discard;
	}
	--count;
}

int list::front() const
{
	assert(count > 0);
	return head->data;
}

int list::back() const
{
	assert(count > 0);
	return tail->data;
}

listiterator list::begin() const
{
	listiterator it;
	it.pos = head;
	it.container = this;
	return it;
}

listiterator list::end() const
{
	listiterator it;
	it.pos = nullptr;
	it.container = this;
	return it;
}

void list::insert(listiterator &it, int data)
{
	if (it.pos == nullptr)
	{
		//empty list or append at the tail
		push_back(data);
		it.pos = tail;
	}
	else if (it.pos == head)
	{
		push_front(data);
		it.pos = head;
	}
	else
	{
		// between 2 nodes
		node *p = new node(data);
		node *left = it.pos->prev;
		node *right = it.pos;
		p->prev = left;
		p->next = right;
		left->next = p;
		right->prev = p;
		it.pos = p;
		++count;
	}
}

void list::erase(listiterator &it)
{
	assert(it.pos != nullptr);
	if (head == tail)
	{
		// only one node
		delete head;
		head = tail = nullptr;
		it.pos = nullptr;
	}
	else if (it.pos == head)
	{
		node *discard = head;
		head = head->next;
		head->prev = nullptr;
		delete discard;
		it.pos = head;
	}
	else if (it.pos == tail)
	{
		node *discard = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete discard;
		it.pos = nullptr; // past the end
	}
	else
	{
		// between two nodes
		node *discard = it.pos;
		node *left = it.pos->prev;
		node *right = it.pos->next;
		left->next = right;
		right->prev = left;
		delete discard;
		it.pos = right;
	}
	--count;
}
