#pragma once
#include "node.h"
#include "list.h"

class list; // forward declaration

class listiterator
{
private:
	node *pos;
	const list *container;

public:
	listiterator();
	int get() const;
	void next();
	void prev();

	bool equals(listiterator) const;

	friend class list;
};