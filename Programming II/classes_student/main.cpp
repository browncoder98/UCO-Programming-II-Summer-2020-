#include <iostream>
using namespace std;
#include "student.h"

int main()
{

	// student s1; // constructor is called (implicitly)
	student s2(1, 3.5, "John");

	cout << s2.get_name() << endl;
	s2.set_gpa(3.99);
	cout << s2.get_gpa() << endl;

	student *p;
	//p = new student;

	student *p2;
	p2 = new student(2, 2.5, "Bill");

	cout << p2->get_name() << endl;
	cout << p2->get_id() << endl;

	student a[4];
	a[0] = student(10, 2.9, "John");
	a[1] = student(12, 3.9, "Mary");

	student *x = new student[3];
	x[0] = student(13, 1.9, "Bill");
	x[1] = student(14, 3.9, "Sue");
	x[2] = student(15, 2.9, "Kelly");

	student *y;
	y = x;
	for (int i = 0; i < 3; i++)
	{
		cout << x[i].get_name() << " " << x[i].get_id() << endl;
		cout << (x + i)->get_name() << " " << (x + i)->get_id() << endl;
		cout << y->get_name() << " " << y->get_id() << endl;
		cout << (*y).get_name() << " " << (*y).get_id() << endl;
		++y;
	}
}
