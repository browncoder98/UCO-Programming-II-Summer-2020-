#pragma once

class node
{
private:
	int data;
	node *link;

public:
	node(int);

	friend class slist;
};