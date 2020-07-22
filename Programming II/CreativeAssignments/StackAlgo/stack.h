#pragma once
#define size 60

class Stack
{
	int arr[size];
	int top;

public:
	Stack(); //default constructor
	void push(int);
	int pop();		//removes the top most element
	int peep();		//returns the top most element but does not decrement the value of the top most element
	bool isfull();	//Returns statements when the stack is full
	bool isempty(); // Return statements when the stack is empty
};