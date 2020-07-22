#include "slist.h"
#include <cassert>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insert_v(vector<int> &, int, int);
void remove_v(vector<int> &, int);

int main()
{
	slist m;
	assert(m.size() == 0);
	m.append(5);
	m.append(6);
	assert(m.size() == 2);

	assert(m.get(0) == 5);
	assert(m.get(1) == 6);
	m.append(7);
	assert(m.get(2) == 7);

	slist mm;
	mm.insert(0, 10); // 10
	mm.insert(1, 20); // 10 20
	mm.insert(0, 15); // 15 10 20
	assert(mm.get(0) == 15);
	assert(mm.get(1) == 10);
	assert(mm.get(2) == 20);

	mm.insert(1, 99); // 15 99 10 20
	assert(mm.get(0) == 15);
	assert(mm.get(1) == 99);
	assert(mm.get(2) == 10);
	assert(mm.get(3) == 20);
	assert(mm.size() == 4);

	mm.insert(2, 77); // 15 99 77 10 20
	assert(mm.get(0) == 15);
	assert(mm.get(1) == 99);
	assert(mm.get(2) == 77);
	assert(mm.get(3) == 10);
	assert(mm.get(4) == 20);
	assert(mm.size() == 5);

	mm.remove(0); // 99 77 10 20
	assert(mm.get(0) == 99);
	assert(mm.get(1) == 77);
	assert(mm.get(2) == 10);
	assert(mm.get(3) == 20);
	assert(mm.size() == 4);
	mm.remove(0);
	mm.remove(0);
	mm.remove(0); // 20
	assert(mm.get(0) == 20);
	assert(mm.size() == 1);
	mm.remove(0); //
	assert(mm.size() == 0);

	slist a;
	a.append(1);
	a.append(2);
	a.append(3);
	a.append(4);
	a.append(5); // 1 2 3 4 5

	assert(a.index_of(5) == 4);
	assert(a.index_of(4) == 3);
	assert(a.index_of(1) == 0);

	a.remove(4);
	a.remove(3);

	//a.remove(1); // 1 3 4 5
	//assert(a.get(0) == 1);
	//assert(a.get(1) == 3);
	//a.remove(2); // 1 3 5
	//assert(a.get(0) == 1);
	//assert(a.get(1) == 3);
	//assert(a.get(2) == 5);
	//a.remove(1); // 1 5
	//assert(a.get(0) == 1);
	//assert(a.get(1) == 5);
	//a.remove(1);
	//assert(a.get(0) == 1);
	//assert(a.size() == 1);
	//a.remove(0);
	//assert(a.size() == 0);

	//comprehensive testing
	// insert()

	slist test;
	vector<int> v;
	const int N = 5000;

	srand(time(nullptr));
	//cout << RAND_MAX << endl;
	//for (int i = 0; i < 20; i++)
	//{
	//	cout << rand() << " ";
	//}
	//cout << endl;

	test.append(0);
	v.push_back(0);
	for (int i = 1; i < N; i++)
	{
		if (i % 50 == 0)
		{
			test.insert(0, i);
			insert_v(v, 0, i);
			test.insert(test.size(), ++i);
			v.push_back(i);
		}
		else
		{
			int pos = rand() % test.size() + 1;
			test.insert(pos, i);
			insert_v(v, pos, i);
		}
	}

	for (int i = 0; i < test.size(); i++)
	{
		assert(test.get(i) == v[i]);
	}

	// remove

	for (int i = 0; i < N / 2; i++)
	{
		if (i % 50 == 0)
		{
			test.remove(0);
			remove_v(v, 0);
			test.remove(test.size() - 1);
			remove_v(v, v.size() - 1);
		}
		else
		{
			int pos = rand() % test.size();
			test.remove(pos);
			remove_v(v, pos);
		}
	}

	for (int i = 0; i < test.size(); i++)
	{
		assert(test.get(i) == v[i]);
	}

	// index_of
	for (int i = 0; i < test.size(); i++)
	{
		assert(test.index_of(v[i]) == i);
		//if (test.index_of(v[i]) != i)
		//{
		//	cout << i << " | " << v[i] << endl;
		//}
	}
}

void insert_v(vector<int> &v, int pos, int data)
{
	vector<int>::iterator it = v.begin();
	for (int i = 0; i < pos; i++)
	{
		++it;
	}
	v.insert(it, data);
}

void remove_v(vector<int> &v, int pos)
{
	vector<int>::iterator it = v.begin();
	for (int i = 0; i < pos; i++)
	{
		++it;
	}
	v.erase(it);
}