#pragma once
#include <iostream>
using namespace std;

class fraction
{
private:
	int numerator;
	int denominator;
	void normalize();
	int gcd(int, int);
	int compare(const fraction &right) const;

public:
	fraction();			// 0 / 1
	fraction(int);		// numerator / 1
	fraction(int, int); //numerator / denominator
	fraction operator+(const fraction &) const;
	fraction operator-(const fraction &) const;
	fraction operator*(const fraction &)const;
	fraction operator/(const fraction &) const;
	fraction operator-() const;
	bool operator>(const fraction &right) const;
	bool operator>=(const fraction &right) const;
	bool operator<(const fraction &right) const;
	bool operator<=(const fraction &right) const;
	bool operator==(const fraction &right) const;
	fraction operator++();	  // preincrement
	fraction operator--();	  // predecrement
	fraction operator++(int); // postincrement
	fraction operator--(int); // postdecrement
	int n() const;
	int d() const;
};

// Non member function for operator overloading
fraction operator+(int n, const fraction &right);
ostream &operator<<(ostream &out, const fraction &value);
