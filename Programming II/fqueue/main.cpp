#include <iostream>
#include <cassert>
using namespace std;
#include "fqueue.h"

int main()
{
	fqueue q(10);
	assert(q.empty());
	assert(!q.full());
	assert(q.length() == 0);

	q.push(20);
	assert(!q.empty());
	assert(q.length() == 1);
	assert(q.front() == 20);
	assert(q.back() == 20);
	q.push(30);
	assert(q.front() == 20);
	assert(q.back() == 30);
	assert(q.length() == 2);

	q.pop();
	assert(q.front() == 30);
	assert(q.back() == 30);

	q.pop();
	assert(q.empty());

	const int N = 2000;
	fqueue test(N);
	assert(test.empty());
	assert(!test.full());
	assert(test.length() == 0);

	for (int k = 0; k < 10; k++)
	{

		for (int i = 0; i < N; i++)
		{
			test.push(i);
			assert(test.front() == 0);
			assert(test.back() == i);
			assert(!test.empty());
		}
		assert(test.full());

		for (int i = 0; i < N; i++)
		{
			assert(test.front() == i);
			assert(test.back() == N - 1);
			test.pop();
		}
		assert(test.empty());
	}
}