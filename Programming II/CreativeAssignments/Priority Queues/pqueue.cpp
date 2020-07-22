#include <iostream>
#include "pqueue.h"
using namespace std;

void Element::show() // For displaying the elements stored
{
	cout << "Data stored: " << data << "Priority of the data: " << priority << endl;
}

Element::Element(int d, int p)
{
	data = d;
	priority = p;
}

int Element::getdata()
{
	return data;
}

void Element::setdata(int d)
{
	data = d;
}

int Element::getpriority()
{
	return priority;
}

void Element::setpriority(int p)
{
	priority = p;
}

Pqueue::Pqueue()
{
	front = rear = -1;
}

void Pqueue::insert(Element e)
{
	int i;
	if (!isfull())
	{

		if (rear == -1)
		{
			arr[++rear] = e; //Incrementing and storing the first element
		}
		else
		{
			for (i = rear; i >= front; i--) // Travesing the priority queue from right to element and inserting the nth element
			{

				if (e.getpriority() < arr[i].getpriority()) //Comparing the priority of the newly inserted elements with the existing ones for shifting to the right of the queue
				{
					arr[i + 1] = arr[i];
				}
				else
				{
					break; //For getting out of the loop given that nothing needs to be shifted
				}
			}
			arr[i + 1] = e; //For storing the element
			rear++;
		}
	}
	else
	{
		throw "The Queue is full!!";
	}
}

Element Pqueue::remove()
{
	if (!isempty())
	{
		return arr[++front];
	}
	else
	{
		throw "The Queue doesnt have anything inside!!";
	}
}

bool Pqueue::isfull()
{
	return rear == size - 1;
}

bool Pqueue::isempty()
{
	return rear == front;
}
