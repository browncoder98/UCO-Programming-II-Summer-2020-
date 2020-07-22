#include "polynomial.h"
#include <iostream>

using namespace std;

Node::Node(int c, int p)
{
	this->coeff = c;
	this->power = p;
	this->sign = (coeff < 0) ? sign = 1 : sign = 0; // Ternary operator
	this->addrOfNext = 0;
}

void Node::setNode(int c, int p)
{
	this->coeff = c;
	this->power = p;
	this->sign = (coeff < 0) ? sign = 1 : sign = 0;
	this->addrOfNext = 0;
}

void Node::displayNode(Node *tempnode)
{
	cout << "{coeff: " << tempnode->coeff << ", power: " << tempnode->power << "}->";
}

List::List()
{
	tail = 0;
	head = 0;
}

void List::addNodeToHead(int c, int p)
{
	Node *newnode = new Node(c, p);

	if (head == 0)
	{
		head = tail = newnode;
	}
	else
	{
		newnode->addrOfNext = head;
		head = newnode;
	}
}

void List::addNodeToTail(int c, int p)
{
	Node *newnode = new Node(c, p);

	if (head == 0)
	{
		head = tail = newnode;
	}
	else
	{
		tail->addrOfNext = newnode;
		tail = newnode;
	}
}

int List::lenList()
{
	int i = 0;
	Node *tempnode = head;

	while (tempnode != 0)
	{
		i++;
		tempnode = tempnode->addrOfNext;
	}

	return i;
}

void List::displayList()
{
	Node *tempnode = head;

	while (tempnode != 0)
	{
		cout << "{coeff: " << tempnode->coeff << ", power: " << tempnode->power << "}->";
		tempnode = tempnode->addrOfNext;
	}
	cout << endl;
}

Node &List::operator[](int i) // Array Subscript operator overloading
{
	if (i < this->lenList() && i >= 0)
	{
		int j = 0;
		Node *tempnode = this->head;

		while (tempnode != 0 && j < i)
		{
			j++;
			tempnode = tempnode->addrOfNext;
		}

		if (i == j)
		{
			return *tempnode;
		}
		EXIT_SUCCESS;
	}
}

List::~List()
{
	Node *temp;
	while (head != tail)
	{
		temp = new Node(4, 2);
		temp = head;
		head = head->addrOfNext;
		delete temp;
		temp = 0;
	}

	if (head != 0)
	{
		delete head;
		head = 0;
		tail = 0;
	}
}
