#include "Bucky.h"
#include <iostream>

using namespace std;

Bucky::Bucky()
{
	cout << "I am the default constructor!!" << endl; // Testing output on constructors
}

Bucky::~Bucky()
{
	cout << "I am the destructor!!" << endl;
}

void Bucky::printRandomStuff()
{
	cout << "Nice try but no chicken fry" << endl;
}

void Bucky::Rakin() const
{
	cout << "The function created here is a constant function accessed by a constant object" << endl;
}