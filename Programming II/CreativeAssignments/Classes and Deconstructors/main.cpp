/* Creative Assignment 2: Class Components and Destructors */

#include <iostream>
#include "Bucky.h"

using namespace std;

int main()
{
	/* Part-1: Accessing data inside classes using both objects and pointers */

	Bucky BuckyObject;				// Object created to access the function printRandomStuff()
	BuckyObject.printRandomStuff(); // Output created using object

	Bucky *BuckyPointer = &BuckyObject; // Setting the pointer to the memory address of the object created
	BuckyPointer->printRandomStuff();	// Output created using arrow member selection

	/* Part-2: Working with Deconstructors aka Destructors */

	Bucky BuckyObject2; // Random object created to portray how destructors work
	cout << "Why did the programmer wear glasses? Because he couldn't C#" << endl;

	/*Part-3: Creating objects and functions of the type 'const' */

	const Bucky ConstantObject;
	ConstantObject.Rakin(); // Since the object created is a constant and the function is a constant as well, we are able to access it with the use of const keyword
}