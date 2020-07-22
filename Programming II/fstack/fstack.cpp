#include "fstack.h"
#include <cassert>
using namespace std;

fstack::fstack(int s) : size(s), tos(-1)
{
	parray = new int[size];
}

fstack::~fstack()
{
	delete[] parray;
}

bool fstack::empty() const
{
	return tos == -1;
}

bool fstack::full() const
{
	return tos == size - 1;
}

void fstack::push(int data)
{
	assert(!full());
	++tos;
	parray[tos] = data;
}

int fstack::top() const
{
	assert(!empty());
	return parray[tos];
}

void fstack::pop()
{
	assert(!empty());
	--tos;
}