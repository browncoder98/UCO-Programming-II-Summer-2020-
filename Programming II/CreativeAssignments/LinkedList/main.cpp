/* Creative Assignment 5 - Linked List (Adding and Removing data into Nodes using referential pointers) */

#include "linkedlist.h"
#include <iostream>

using namespace std;
int main()
{
	LinkedList l1; // Object created
	l1.AddAtEnd(10);
	l1.AddAtEnd(20);
	l1.AddAtEnd(30);
	l1.AddAtEnd(40);
	l1.AddAtBegin(50);
	l1.AddAtEnd(50);

	l1.display();

	l1.RemoveFromEnd();
	l1.RemoveFromBegin();
	l1.RemoveFromPos(4); // Deletes the element with the node

	l1.AddAtPosition(45, 1); // Adds data into the nth position

	l1.display();

	return 0;
}