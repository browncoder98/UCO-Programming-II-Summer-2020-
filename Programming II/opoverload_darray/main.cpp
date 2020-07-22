#include "darray.h"
#include <iostream>
using namespace std;

void f1(darray m);

int main()
{
	darray d(10);

	d.set(0, 0.5);
	d.set(1, 1.5);
	d.set(2, 2.5);

	double t = d.get(0);
	t = d.get(1);
	t = d.get(2);

	darray e(10);

	// e.operator=(d);
	e = e;
	//e = d; // assignment

	darray f(10);
	// f.operator=(e.operator=(d))
	f = e = d;

	darray t1(5);
	t1.set(0, 6.7);

	// "copy" constructor is called
	// if not given, member-wise copy (shallow copy)
	// t2: copy coinstructor with argument t1
	darray t2 = t1; // int n = k;

	// [] overload

	darray m(5);
	m[0] = 1.6; // m.operator[](0) = 1.6
	m[1] = 2.6;
	m[3] = 4.6;
	double n;
	n = m[0];
	n = m[1];
	n = m[3];

	f1(t2);

	// + operator
	darray m1(5), m2(5);
	m1[0] = 4.5;
	m1[1] = 5.5;
	m2[0] = 2.5;
	m2[1] = 3.5;

	darray m3(5);
	m3 = m1 + m2; // m3 = m1.operator+(m2);

	m3 = m1 + 0.2;
	m3 = 0.3 + m1;
}

void f1(darray m)
{
	// ....
}
