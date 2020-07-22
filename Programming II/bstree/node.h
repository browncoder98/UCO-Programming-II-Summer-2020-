#pragma once

class node
{
private:
	int data;
	node *left;
	node *right;

public:
	node(int);

	friend class bstree;
};