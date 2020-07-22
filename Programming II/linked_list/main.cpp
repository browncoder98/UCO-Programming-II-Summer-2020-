#include "list.h"
#include "listiterator.h"
#include <cassert>

#include <iostream>
using namespace std;

void print(list &);

int main()
{
	list m;
	m.push_back(1);
	assert(m.front() == 1);
	assert(m.back() == 1);

	m.push_back(2);
	assert(m.front() == 1);
	assert(m.back() == 2);

	m.push_front(0);
	assert(m.front() == 0);
	assert(m.back() == 2);

	m.pop_front();
	assert(m.front() == 1);
	assert(m.back() == 2);

	m.pop_back();
	assert(m.front() == 1);
	assert(m.back() == 1);
	m.push_front(2);
	m.push_front(3);
	m.push_front(4);

	listiterator it = m.begin();
	int n = it.get();
	it.next();
	n = it.get();
	it.next();
	n = it.get();
	it.next();
	n = it.get();
	it.next();
	it.prev();
	n = it.get(); //tail
	it.prev();
	n = it.get();

	list test;
	for (int i = 0; i < 5; i++)
	{
		test.push_back(i);
	}
	print(test);

	it = test.begin();
	it.next();
	it.next();
	it.next();
	it.next();
	it.next();
	test.insert(it, 100);
	print(test);

	cout << "testing for erase()" << endl;

	list mm;
	for (int i = 0; i < 5; i++)
	{
		mm.push_back(i * 10);
	}
	print(mm);
	it = mm.begin();
	mm.erase(it);
	print(mm);
	it.next();
	mm.erase(it);
	print(mm);
	it.next();
	mm.erase(it);
	print(mm);
	it.prev();
	mm.erase(it);
	print(mm);
	it.prev();
	mm.erase(it);
	cout << "the only one is erased" << endl;
	print(mm);
}

void print(list &mm)
{

	listiterator iter = mm.begin();
	while (!iter.equals(mm.end()))
	{
		cout << iter.get() << " ";
		iter.next();
	}
	cout << endl;
}