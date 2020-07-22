#pragma once
#include <iostream>
using namespace std;

template <typename T>

class tnode
{
private:
	T data;
	tnode<T> *link;

public:
	tnode(T); // data

	template <typename U>
	friend class tstack;
};

template <typename T>
tnode<T>::tnode(T d)
	: data(d), link(nullptr)
{
}
