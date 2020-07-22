#pragma once
#include "node.h"
#include "listiterator.h"

class listiterator; //forward declaration

class list
{
private:
	node *head;
	node *tail;
	int count;

public:
	list();
	~list();
	int size() const;
	void push_front(int);
	void push_back(int);
	void pop_front();
	void pop_back();
	int back() const;
	int front() const;

	listiterator begin() const;
	listiterator end() const;

	void insert(listiterator &, int);
	void erase(listiterator &);

	friend class listiterator;
};