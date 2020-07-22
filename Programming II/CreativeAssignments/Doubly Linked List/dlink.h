#pragma once

struct Node
{
	int data;
	Node *next;
	Node *prev;
};

class DoublyList
{
public:
	Node *head; //head for the list

	DoublyList(); // Default Constructor

	Node *create(int); // For the creation of the doubly linked list
	void InsertBegin(int);
	void Display();
	Node *Merge(Node **, Node **); // Array of pointers used for merge operation
	void MergeSort(Node **);
	void Split(Node **, Node **, Node *);
};