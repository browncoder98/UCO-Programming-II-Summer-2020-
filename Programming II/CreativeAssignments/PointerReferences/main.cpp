/* Creative assignment 1: Intro to Pointers and References with Pointers */

#include <iostream>
using namespace std;

// Prototyping the functions declared:

void passByValue(int x);
void passByReference(int *x);

int main()
{
	/* Intro to Pointers: */

	int tuna = 8;
	cout << &tuna << endl; // Accessing the memory address of tuna using '&'

	int *tunaPointer; //Declaring the pointer variable for tuna
	tunaPointer = &tuna;

	cout << tunaPointer << endl; // No need for * since * used once when pointer was declared

	/* Intro to references with Pointers: */

	int Rakin = 15;	 // Variable to be passed onto the passByValue function
	int Justin = 13; // Variable to be passed onto the passByReference function

	cout << "The initial value of Rakin is " << Rakin << endl;
	cout << "The initial value of Justin is " << Justin << endl;

	passByValue(Rakin);
	passByReference(&Justin); // &Justin used as we are passing pointer arguments

	cout << "The final value of Rakin is " << Rakin << endl;   // Value and attributes unchanged
	cout << "The final value of Justin is " << Justin << endl; // Value and attributes changed
}

void passByValue(int x)
{
	x = 99; // Creating a copy of the variable Rakin
}

void passByReference(int *x)
{
	*x = 66; // Creating a function for referencing pointers
}