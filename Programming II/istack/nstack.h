#pragma once

class nstack
{
private:
	class node
	{
	public:
		int data;
		node *link;
		node(int); // data
	};
	node *ptop;

public:
	nstack();
	~nstack();
	void push(int);
	void pop();
	int top() const;
	bool empty() const;
	bool full() const;
};
