#include "deque.h"
#include <cassert>
#include <iostream>
#include <random>
#include <ctime>
#include <vector>

using namespace std;

void push_front_vector(vector<int> &, int);
void pop_front_vector(vector<int> &);

int main()
{
	deque m;
	assert(m.length() == 0);
	m.push_back(5);
	assert(m.front() == 5);
	assert(m.back() == 5);
	m.push_back(6);
	assert(m.front() == 5);
	assert(m.back() == 6);
	assert(m.length() == 2);

	m.push_front(7);
	assert(m.front() == 7);
	assert(m.back() == 6);
	assert(m.length() == 3);

	m.push_front(8);
	assert(m.front() == 8);
	assert(m.back() == 6);
	assert(m.length() == 4);

	// 8 7 5 6
	m.pop_front();
	assert(m.front() == 7);
	assert(m.back() == 6);
	assert(m.length() == 3);

	m.pop_front();
	assert(m.front() == 5);
	assert(m.back() == 6);
	assert(m.length() == 2);

	// 5 6
	m.push_front(4);
	m.push_back(7);
	//4 5 6 7
	m.pop_back();
	assert(m.front() == 4);
	assert(m.back() == 6);
	m.pop_back();
	assert(m.front() == 4);
	assert(m.back() == 5);
	assert(m.length() == 2);
	m.pop_back();
	assert(m.front() == 4);
	assert(m.back() == 4);
	assert(m.length() == 1);
	m.pop_back();
	assert(m.length() == 0);
	m.push_back(88);
	m.push_back(99);

	// comprehensive testing

	default_random_engine gen(time(0)); //
	uniform_int_distribution<int> dist(1, 6);

	//for (int i = 0; i < 100; i++)
	//{
	//	cout << dist(gen) << " ";
	//}

	vector<int> v;
	const int N = 6000;

	deque test;
	assert(test.length() == 0);

	for (int i = 0; i < N; i++)
	{
		switch (dist(gen))
		{
		case 1:
		case 2: //push_front();
			test.push_front(i);
			push_front_vector(v, i);
			break;
		case 3:
		case 4: //push_back();
			test.push_back(i);
			v.push_back(i);
			break;
		case 5: //pop_front();
			if (test.length() == 0)
				break;
			test.pop_front();
			pop_front_vector(v);
			break;
		case 6: //pop_back();
			if (test.length() == 0)
				break;
			test.pop_back();
			v.pop_back();
			break;
		}
	}
	cout << test.length() << endl;

	//compare v with test

	for (int i = 0; i < v.size(); i++)
	{
		assert(test.front() == v[i]);
		test.pop_front();
	}
}

void push_front_vector(vector<int> &v, int data)
{
	vector<int>::iterator it = v.begin();
	v.insert(it, data);
}

void pop_front_vector(vector<int> &v)
{
	vector<int>::iterator it = v.begin();
	v.erase(it);
}