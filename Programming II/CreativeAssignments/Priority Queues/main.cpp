/* Creative Assignment 4: Ascending Priority Queue */

#include <iostream>
#include <string>
#include "pqueue.h"

using namespace std;

int main()
{
	Pqueue pq; // Object created for use
	int data, choice, priority;
	Element e; // Object for Element class

	while (true) // Infinite loop to display the menu
	{
		cout << "1. Insert an element into the queue" << endl;
		cout << "2. Remove an element from the queue" << endl;
		cout << "3. Exit the program" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			try // For accepting the data and priority from the user
			{
				cout << "Enter data: " << endl;
				cin >> data;
				cout << "Enter priority: " << endl;
				cin >> priority;
				e.setdata(data);
				e.setpriority(priority);
				pq.insert(e); // Inserting the object e into the priority queue
			}
			catch (const char *msg)
			{
				cout << msg << endl;
			}
			break;
		case 2:
			try
			{
				cout << "An element has been removed " << endl;
				pq.remove().show(); //Returns the object of the element class to return the show function
			}
			catch (const char *msg)
			{
				cout << msg << endl;
			}
			break;
		case 3: // For quitting the program
			exit(0);
		}
	}
	return 0;
}