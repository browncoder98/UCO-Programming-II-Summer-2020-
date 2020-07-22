#include <iostream>
using namespace std;

void f1(int n)
{
	cout << "f1: " << n << endl;
}

void f2(int n)
{
	cout << "f2: " << n << endl;
}

void f3(double d)
{
	cout << "f3: " << d << endl;
}

int main()
{
	int n;
	// integer pointer
	int *p = &n;
	// value in n ==> *p

	// function pointer
	void (*f)(int);

	f = f1; // name of the func == address of the function
	void (*fd)(double);
	fd = f3;
	(*f)(10);
	(*fd)(1.23);
}