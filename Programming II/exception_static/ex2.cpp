#include <iostream>
using namespace std;

int f()
{
	static int s = 0;
	s = s + 1;
	return s;
}

int main()
{
	int r;
	r = f();
	cout << "r = " << r << endl;
	r = f();
	cout << "r = " << r << endl;
	r = f();
	cout << "r = " << r << endl;
}