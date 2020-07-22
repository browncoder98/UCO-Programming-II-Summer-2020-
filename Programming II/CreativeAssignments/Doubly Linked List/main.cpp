/* Creative Assignment 6 : Merge Sort using Doubly Linked Lists */

#include "dlink.h"

#include <iostream>
using namespace std;

int main()
{
	DoublyList list1;

	//list 1 : 7->20->13->8->34->15
	list1.InsertBegin(15);
	list1.InsertBegin(34);
	list1.InsertBegin(8);
	list1.InsertBegin(13);
	list1.InsertBegin(20);
	list1.InsertBegin(7);

	cout << "Before Sorting:";
	list1.Display();

	list1.MergeSort(&list1.head);

	cout << "\n\nAfter Sorting:";
	list1.Display();
	return 0;
}
