#pragma once

#include <string>
using namespace std;

struct Patient
{
	int priority;
	string name;
	Patient(int _priority, string _name)
	{
		priority = _priority;
		name = _name;
	}
};

class PatientQueue
{

public:
	PatientQueue();
	~PatientQueue(); // release memory and delete queue
	int size();
	bool isEmpty();
	void enqueue(int priority, string name);
	Patient *dequeue(); // returns pointer to patient record and removes from array
	void printList();	// print the array
private:
	void swap(int index1, int index2); // swap the contents in the array
	Patient *waitlist[100];
	int lastIndex;
};