#pragma once

class Node
{
public:
	int coeff;
	int power;
	bool sign; // 1 for neg, 0 for pos
	Node *addrOfNext;
	Node(int c, int p);
	void setNode(int c, int p);
	void displayNode(Node *tempnode);
};

class List
{
public:
	Node *tail, *head;
	List();
	void addNodeToHead(int c, int p);
	void addNodeToTail(int c, int p);
	int lenList();
	void displayList();
	Node &operator[](int i);
	~List();
};
