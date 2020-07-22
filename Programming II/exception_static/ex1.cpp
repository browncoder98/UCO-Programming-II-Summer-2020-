#include <iostream>
#include <string.h>
#include "student.h"
using namespace std;

int read_nstudents()
{
	// read from the file & others
	// return # of students
	// return -1 if error occured in the above step

	int n = 10;
	return n;
}

double divide(double n, double d)
{
	if (d == 0.0)
	{
		string e = "divide by zero exception";
		throw e; // abnormal (alternate) way of exiting the func
	}
	return n / d; // normal way of exiting the function
}

int main()
{
	int ns = read_nstudents();
	if (ns < 0)
	{
		// error occur
		return -1;
	}
	// process the students info

	try
	{
		double r = divide(10, 0);
		cout << "div result is " << r << endl;
	}
	catch (string e)
	{
		cout << "string exception: " << e << endl;
	}
	catch (int e)
	{
		cout << "int exception: " << e << endl;
	}
	catch (char c)
	{
		cout << "char exception: " << c << endl;
	}

	cout << "------------------" << endl;

	student s1;
	try
	{
		s1.set_gpa(3.5);
		s1.set_id(-1);
	}
	catch (student::out_of_range_gpa e)
	{
		cout << "gpa is out range!" << endl;
	}
	catch (student::invalid_id e)
	{
		cout << "invalid id exception" << endl;
	}
}