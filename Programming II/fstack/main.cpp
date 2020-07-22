#include <iostream>
#include <cassert>

using namespace std;

#include "fstack.h"

int main()
{
	fstack s1(5);
	assert(s1.empty());
	assert(!s1.full());

	s1.push(10);
	assert(!s1.empty());
	assert(!s1.full());

	assert(s1.top() == 10);
	s1.pop();
	assert(s1.empty());

	s1.push(5);
	s1.push(6);
	s1.push(7);
	assert(s1.top() == 7);
	s1.pop();
	assert(s1.top() == 6);

	//more comprehensive testing with large set of data
	const int S = 2000;
	fstack test(S);
	assert(test.empty());
	assert(!test.full());

	for (int i = 0; i < S - 1; i++)
	{
		test.push(i);
		assert(!test.empty());
		assert(!test.full());
	}
	test.push(S - 1);
	assert(test.full());

	for (int i = S - 1; i >= 0; i--)
	{
		assert(test.top() == i);
		test.pop();
		assert(!test.full());
	}
	assert(test.empty());
}