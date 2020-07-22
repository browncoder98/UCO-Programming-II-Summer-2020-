#include "myutil.h"
#include <cassert>
using namespace std;

int main()
{
	assert(myutil::sum(10) == 55);
	assert(myutil::sum(100) == 5050);
	assert(myutil::fact(4) == 1 * 2 * 3 * 4); // 4! = 1x2x3x4
	assert(myutil::fact(6) == 1 * 2 * 3 * 4 * 5 * 6);

	int n = myutil::pow(2, 10); // 2^10 = 1024
	assert(n == 1024);
	assert(myutil::pow(10, 4) == 10000);

	assert(myutil::fib(3) == 2);
	assert(myutil::fib(6) == 8);
	assert(myutil::fib(9) == 34);

	int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	assert(myutil::sum(values, 10) == 55);

	int *data = new int[100];
	for (int i = 1; i <= 100; i++)
	{
		data[i - 1] = i;
	}
	assert(myutil::sum(data, 100) == 5050);

	int a[] = {9, 10, 1, 2, 3, 6, 55, 20, 4, 3};
	assert(myutil::largest(a, 10) == 55);

	myutil::hanoi(5);
}