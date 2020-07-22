#pragma once
#include <cassert>
using namespace std;

template <typename T>
class tarray
{
private:
	T *parray;
	int capacity; // max allocated array size
public:
	tarray(int);
	tarray(const tarray<T> &); // copy constructors
	~tarray();
	void set(int, T);
	T get(int) const;
	tarray<T> &operator=(const tarray<T> &);
	T operator[](int) const; //rvalue
	T &operator[](int);
	tarray<T> operator+(const tarray<T> &) const;
	tarray<T> operator+(T) const;

	// non-member function
	template <typename U>
	friend tarray<U> operator+(U, const tarray<U> &); // a = (U) + b
};

template <typename T>
tarray<T>::tarray(int c) : capacity(c)
{
	parray = new T[capacity];
}

//copy constructor

template <typename T>
tarray<T>::tarray(const tarray<T> &right)
{
	if (this == &right)
	{
		return;
	}
	capacity = right.capacity;
	parray = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		parray[i] = right.parray[i];
	}
}

template <typename T>
tarray<T>::~tarray()
{
	delete[] parray;
}

template <typename T>
void tarray<T>::set(int pos, T value)
{
	assert(0 <= pos && pos < capacity);
	parray[pos] = value;
}

template <typename T>
T tarray<T>::get(int pos) const
{
	assert(0 <= pos && pos < capacity);
	return parray[pos];
}

template <typename T>
tarray<T> &tarray<T>::operator=(const tarray<T> &right)
{
	// of the same size only
	assert(capacity == right.capacity);
	if (this == &right)
	{
		return *this;
	}
	for (int i = 0; i < capacity; i++)
	{
		parray[i] = right.parray[i];
	}
	return *this;
}

template <typename T>
T tarray<T>::operator[](int pos) const
{
	assert(0 <= pos && pos < capacity);
	return parray[pos];
}

template <typename T>
T &tarray<T>::operator[](int pos)
{
	assert(0 <= pos && pos < capacity);
	return parray[pos];
}

template <typename T>
tarray<T> tarray<T>::operator+(const tarray<T> &right) const
{
	assert(capacity == right.capacity);
	tarray<T> result(capacity);
	for (int i = 0; i < capacity; i++)
	{
		result[i] = parray[i] + right[i];
		// result.parray[i] = parray[i] + right.parray[i];
	}
	return result;
}

template <typename T>
tarray<T> tarray<T>::operator+(T value) const
{
	tarray<T> result(capacity);
	for (int i = 0; i < capacity; i++)
	{
		result[i] = parray[i] + value;
	}
	return result;
}

// non-member function

template <typename T>
tarray<T> operator+(T value, const tarray<T> &right)
{
	tarray<T> result(right.capacity);
	for (int i = 0; i < right.capacity; i++)
	{
		result[i] = value + right.parray[i];
	}
	return result;
}
