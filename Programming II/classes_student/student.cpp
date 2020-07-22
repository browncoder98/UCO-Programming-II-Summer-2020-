#include "student.h"

//initializer-list
student::student()
	: id(-1), gpa(0), name("no name")
{
}

student::student(int i, double g, string n)
	: id(i), gpa(g), name(n)
{
}

int student::get_id() const
{
	return id;
}

double student::get_gpa() const
{
	return gpa;
}

string student::get_name() const
{
	return name;
}

void student::set_gpa(double g)
{
	gpa = g;
}