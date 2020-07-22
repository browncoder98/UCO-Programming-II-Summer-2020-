/* Creative Assignment 11 : Implementing Heap with Priority Queue by making a Hopsital Patient List */

#include "Heap_PriorityQueue.h"
#include <iostream>
#include <string>
using namespace std;

PatientQueue::PatientQueue()
{
	//ctor
	lastIndex = 0; //initiallizes lastIndex to 0;

	for (int i = 0; i < 100; i++)
	{
		waitlist[i] = NULL;
	}
}

PatientQueue::~PatientQueue()
{
	//dtor
	cout << "===\nWe're CLOSING! Deleting patient queue!" << endl;
	for (int i = 1; i < lastIndex; i++)
	{
		cout << "Removing " << waitlist[i]->name << " from queue." << endl;
		waitlist[i] = NULL;
		delete waitlist[i];
	}
}

/*
 * Function name: size
 * Purpose: Returns value of lastIndex
 * @return - int value of lastIndex
*/
int PatientQueue::size()
{
	return lastIndex;
}

/*
 * Function name: swap
 * Purpose: swap the values in the array to prioritize with smallest value
 * @return - none
*/
void PatientQueue::swap(int index1, int index2)
{
	int priority = waitlist[index1]->priority;
	string name = waitlist[index1]->name;
	Patient *tmp = new Patient(priority, name);

	for (; index1 * 2 <= lastIndex; index1 = index2)
	{
		index2 = index1 * 2;
		if (index2 != lastIndex && waitlist[index2 + 1]->priority < waitlist[index2]->priority)
		{
			index2++;
		}
		if (waitlist[index2]->priority < tmp->priority)
		{
			waitlist[index1] = waitlist[index2];
		}
		else
		{
			break;
		}
		waitlist[index2] = tmp;
	}
}

/*
 * Function name: isEmpty
 * Purpose: checks to see if the array has any values added to it
 * @return - true if array is empty
*/
bool PatientQueue::isEmpty()
{
	if (lastIndex == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
 * Function name: enqueue
 * Purpose: adds new value to array and prioritizes it by priority number
 * @return - none
*/
void PatientQueue::enqueue(int priority, string name)
{
	Patient *tmp = new Patient(priority, name);

	if (lastIndex == 99)
	{
		throw string("Heap Storage is full!");
	}
	else
	{
		int hole = ++lastIndex;
		for (; hole > 1 && priority < waitlist[hole / 2]->priority; hole /= 2)
		{
			waitlist[hole] = waitlist[hole / 2];
		}
		waitlist[hole] = tmp;
		cout << "===\nAdding " << waitlist[hole]->priority << " " << waitlist[hole]->name << endl;
		printList();
	}
}

/*
 * Function name: dequeue
 * Purpose: removes minimum priority value from queue
 * @return - pointer to the value being removed
*/
Patient *PatientQueue::dequeue()
{
	int priority = waitlist[1]->priority;
	string name = waitlist[1]->name;
	Patient *tmp = new Patient(priority, name);

	if (isEmpty())
	{
		throw string("Queue is empty!");
	}
	else
	{
		cout << "===\nProcessing " << waitlist[1]->priority << " " << waitlist[1]->name << endl;
		waitlist[1] = waitlist[lastIndex--];
		swap(1, lastIndex);
	}

	return tmp;
}

/*
 * Function name: printList
 * Purpose: to print the priority list in array order
 * @return - none
*/
void PatientQueue::printList()
{
	cout << "===\nPatients Waiting" << endl;
	if (isEmpty())
	{
		cout << "No one is waiting!" << endl;
	}
	else
	{
		for (int i = 1; i <= lastIndex; i++)
		{
			cout << "[" << waitlist[i]->priority << "] " << waitlist[i]->name << endl;
		}
	}
}