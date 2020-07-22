class Node
{
	int data;
	Node *next; // referential pointer

public:
	int getData();
	void setData(int);
	Node *getNext();
	void setNext(Node *);
};