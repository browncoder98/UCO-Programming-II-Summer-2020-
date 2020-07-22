#pragma once
#include "node.h"

class slist
{
private:
	node *head;
	node *tail;
	int count;

public:
	slist();
	~slist();
	void append(int);
	int size() const;
	int get(int) const;
	void insert(int, int);	 // pos, data
	void remove(int);		 // pos
	int index_of(int) const; // 1st occurence of data
};