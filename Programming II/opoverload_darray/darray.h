#pragma once

class darray
{
private:
	double *parray;
	int capacity; // max allocated array size
public:
	darray(int);
	darray(const darray &); // copy constructors
	~darray();
	void set(int, double);
	double get(int) const;
	darray &operator=(const darray &);
	double operator[](int) const; //rvalue
	double &operator[](int);
	darray operator+(const darray &) const;
	darray operator+(double) const;

	// non-member function
	friend darray operator+(double, const darray &); // a = (double) + b
};
