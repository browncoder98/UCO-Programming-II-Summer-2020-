#include "istack.h"
#include "nstack.h"
#include <cassert>
#include <iostream>

using namespace std;

int main()
{
	const int N = 5000;

	istack s1;
	assert(s1.empty());
	assert(!s1.full());

	for (int i = 0; i < N; i++)
	{
		s1.push(i);
		assert(!s1.empty());
	}
	assert(!s1.full());

	for (int i = N - 1; i >= 0; i--)
	{
		assert(s1.top() == i);
		s1.pop();
	}
	assert(s1.empty());

	//nstack

	nstack s2;
	assert(s2.empty());
	assert(!s2.full());

	for (int i = 0; i < N; i++)
	{
		s2.push(i);
		assert(!s2.empty());
	}
	assert(!s2.full());

	for (int i = N - 1; i >= 0; i--)
	{
		assert(s2.top() == i);
		s2.pop();
	}
	assert(s2.empty());
}