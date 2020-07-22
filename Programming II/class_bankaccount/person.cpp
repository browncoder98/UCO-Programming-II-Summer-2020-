#include <iostream>
using namespace std;

#include "person.h"

person::person() : name("no name"), age(-1)
{
	cout << "person::person()" << endl;
}

person::person(string n, int a)
	: name(n), age(a)
{
	cout << "person::person(string, int)" << endl;
}

person::~person()
{
	cout << "person::~person()" << endl;
}

string person::get_name() const
{
	return name;
}

int person::get_age() const
{
	return age;
}