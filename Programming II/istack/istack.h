#pragma once

#include "node.h"

class istack
{
private:
	node *ptop;

public:
	istack();
	~istack();
	void push(int);
	void pop();
	int top() const;
	bool empty() const;
	bool full() const;
};
