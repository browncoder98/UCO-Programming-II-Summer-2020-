#include "fraction.h"
#include <iostream>

using namespace std;

int main()
{
	fraction f1;
	fraction f2(3);
	fraction f3(2, 4);

	f1 = f2 + f3; // f1 = f2.operator+(f3)
	f1 = 2 + f3;  // operator+(2, f3)

	fraction a(2, 3), b(4, 7);
	fraction c = a - b;
	c = a * b;
	c = a / b;

	c = -a;

	bool t = a > b;
	t = a >= b;
	t = a < b;
	t = a <= b;
	t = a == b;

	// int n = 2; y = ++n;

	fraction m(1, 3);
	fraction k;
	k = ++m; // 1/3 + 1 = 4/3
	k = --m;
	k = --m;

	// post increment ++
	// int n = 2; y = n++

	fraction y(2, 5);
	fraction z;
	z = y++; // z = 2/5
	k = y;	 // k = 7/5
	z = y--;
	z = y--;

	cout << "y is " << y << endl;
	cout << "z is " << z << endl;
	cout << endl;
}