#include "student.h"

int student::count = 0;

student::student() : gpa(0), id(0)
{
	++count;
}

student::student(float g) : gpa(g), id(0)
{
	++count;
}
student::student(int i) : gpa(0), id(i)
{
	++count;
}
student::student(float g, int i) : gpa(g), id(i)
{
	++count;
}
student::~student()
{
	--count;
}

int student::get_count()
{
	return count;
}

void student::set_gpa(float gpa)
{
	if (gpa < 0 || gpa > 4.0)
	{
		throw out_of_range_gpa();
	}
	this->gpa = gpa;
}

void student::set_id(int id)
{
	if (id < 0)
	{
		throw invalid_id();
	}
	this->id = id;
}