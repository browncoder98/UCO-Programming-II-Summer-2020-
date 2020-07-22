#include "node.h"

class LinkedList
{
	Node *head;

public:
	LinkedList();		  // Default constructor
	void AddAtEnd(int);	  // Adds node to the end
	void AddAtBegin(int); // Adds node to the beginning
	int getCount();
	void AddAtPosition(int, int); // data, position
	void RemoveFromEnd();
	void RemoveFromBegin();
	void RemoveFromPos(int);
	void display();
	~LinkedList(); // Destructor to prevent memory leakage
};