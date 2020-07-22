#include <iostream>
#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList()
{
	head = NULL;
}

void LinkedList::AddAtEnd(int data)
{
	Node *newnode = new Node; //Allocating memory
	newnode->setData(data);
	newnode->setNext(NULL);
	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		Node *trav = head; // Pointer created for traversal
		while (trav->getNext() != NULL)
		{
			trav = trav->getNext();
		}
		trav->setNext(newnode); // Adding a node at the end of the linked list
	}
}

void LinkedList::AddAtBegin(int data)
{
	Node *newnode = new Node;
	newnode->setData(data);
	newnode->setNext(NULL);

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->setNext(head);
		head = newnode;
	}
}

int LinkedList::getCount() // Gives the number of existing nodes
{
	int cnt = 0;
	Node *trav = head;
	while (trav != NULL)
	{
		cnt++;
		trav = trav->getNext();
	}
	return cnt;
}
void LinkedList::AddAtPosition(int data, int pos)
{
	Node *newnode = new Node;
	newnode->setData(data);
	newnode->setNext(NULL);

	Node *trav = head;
	if (pos == 1)
	{
		AddAtBegin(data);
	}
	else if (pos > getCount())
	{
		cout << "Invalid Position" << endl;
	}
	else
	{
		while (pos > 2)
		{
			trav = trav->getNext();
			pos--;
		}
		newnode->setNext(trav->getNext());
		trav->setNext(newnode);
	}
}
void LinkedList::RemoveFromEnd()
{
	Node *trav, *follow;
	trav = head;
	follow = trav;
	while (trav->getNext() != NULL)
	{
		follow = trav;
		trav = trav->getNext();
	}
	follow->setNext(NULL);
	delete trav;
}

void LinkedList::RemoveFromBegin()
{
	Node *trav = head;
	head = head->getNext();
	delete trav; // deletes the first node
}

void LinkedList::RemoveFromPos(int pos)
{
	Node *trav, *follow;
	trav = head;
	follow = trav;
	if (pos == 1)
	{
		RemoveFromBegin();
	}
	else if (pos == getCount())
	{
		RemoveFromEnd();
	}
	else if (pos > getCount())
	{
		cout << "Invalid Position!!" << endl;
		return;
	}
	else
	{

		while (pos > 1)
		{
			follow = trav;
			trav = trav->getNext();
			pos--;
		}
		follow->setNext(trav->getNext()); // Bypasing the node which needs to be deleted
		delete trav;
	}
}

void LinkedList::display() //Displaying the data part of each node
{
	Node *trav = head;
	while (trav != NULL)
	{
		cout << trav->getData() << "  ";
		trav = trav->getNext();
	}
	cout << endl;
}

LinkedList::~LinkedList()
{
	Node *trav = head;
	while (head != NULL)
	{
		trav = head;
		head = head->getNext(); // To move the head pointer
		delete trav;			// To delete  the node
	}
}