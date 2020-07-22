#include "person.h"

person::person()
	: name("no name"), age(-1)
{
}

person::person(string n, int a)
	: name(n), age(a)
{
}

person person::operator+(const person &right)
{
	string n = name + right.name;
	int a = age + right.age;
	return person(n, a);
}