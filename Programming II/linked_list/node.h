#pragma once

class node
{
private:
	int data;
	node *next;
	node *prev;

public:
	node(int);

	friend class list;
	friend class listiterator;
};