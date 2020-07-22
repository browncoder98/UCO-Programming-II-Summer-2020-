#include "student.h"

#include <iostream>
using namespace std;

int main()
{
	cout << "# of student objects alive: " << student::get_count() << endl;
	student *s1 = new student;
	student *s2 = new student(3.5f);
	cout << "# of student objects alive: " << student::get_count() << endl;
	delete s1;
	cout << "# of student objects alive: " << student::get_count() << endl;
}