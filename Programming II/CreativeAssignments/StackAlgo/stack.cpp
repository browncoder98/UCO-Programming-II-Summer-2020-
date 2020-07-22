#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack()
{
	top = -1;
}

void Stack::push(int data)
{
	if (!isfull())
	{
		arr[++top] = data;
	}
	else
	{
		throw "Stack is full!!!";
	}
}

int Stack::pop()
{
	if (!isempty())
	{
		return arr[top--];
	}
	else
	{
		throw "Stack is empty!!!";
	}
}

int Stack::peep() // Works similarly to top() in stacks
{
	if (!isempty())
	{
		return arr[top];
	}
	else
	{
		throw "Stack is empty";
	}
}

bool Stack::isempty()
{
	return top == -1;
}

bool Stack ::isfull()
{
	return top == size - 1;
}