#include "node.h"

int Node::getData()
{
	return data;
}

void Node::setData(int d)
{
	data = d;
}

Node *Node::getNext()
{
	return next;
}

void Node::setNext(Node *n)
{
	next = n;
}