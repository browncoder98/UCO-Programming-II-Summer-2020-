#pragma once
#define size 5

class Element
{
	int data;
	int priority;

public:
	Element(int = 0, int = 0); //Parametised constructors with default value
	int getdata();
	void setdata(int);
	int getpriority();
	void setpriority(int);
	void show(); //Display the value and priority of the elements in the queue
};

class Pqueue
{
	Element arr[size]; //Static array size set
	int rear, front;

public:
	Pqueue(); //Default constructor
	void insert(Element);
	Element remove();
	bool isfull();
	bool isempty();
};