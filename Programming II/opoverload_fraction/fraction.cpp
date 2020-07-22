#include "fraction.h"
#include <cassert>
using namespace std;

int fraction::gcd(int n, int m)
{ // Ecluid's Algorithm
	assert(n > 0 && m > 0);
	while (n != m)
	{
		if (n < m)
		{
			m = m - n;
		}
		else
		{
			n = n - m;
		}
	}
	return n;
}

void fraction::normalize()
{
	// normalize fraction by
	// (1) moving sign to numerator
	// (2) ensuring numerator and denominator have no common divisors

	int sign = 1;
	if (numerator < 0)
	{
		sign = -1;
		numerator = -numerator;
	}
	if (denominator < 0)
	{
		sign = -sign;
		denominator = -denominator;
	}
	assert(denominator != 0);
	int d = 1;
	if (numerator > 0)
	{
		d = gcd(numerator, denominator);
		numerator = sign * (numerator / d);
		denominator = denominator / d;
	}
}

fraction::fraction()
	: numerator(0), denominator(1)
{
}

fraction::fraction(int n)
	: numerator(n), denominator(1)
{
}

fraction::fraction(int n, int d)
	: numerator(n), denominator(d)
{
	normalize();
}

int fraction::n() const
{
	return numerator;
}

int fraction::d() const
{
	return denominator;
}

fraction fraction::operator+(const fraction &right) const
{
	int r_n = numerator * right.denominator + right.numerator * denominator;
	int r_d = denominator * right.denominator;
	return fraction(r_n, r_d);
}

fraction fraction::operator-(const fraction &right) const
{
	int r_n = numerator * right.denominator - right.numerator * denominator;
	int r_d = denominator * right.denominator;
	return fraction(r_n, r_d);
}

fraction fraction::operator*(const fraction &right) const
{
	int r_n = numerator * right.numerator;
	int r_d = denominator * right.denominator;
	return fraction(r_n, r_d);
}

fraction fraction::operator/(const fraction &right) const
{
	int r_n = numerator * right.denominator;
	int r_d = denominator * right.numerator;
	return fraction(r_n, r_d);
}

fraction fraction::operator-() const
{
	return fraction(-numerator, denominator);
}

int fraction::compare(const fraction &right) const
{
	return numerator * right.denominator - right.numerator * denominator;
}

bool fraction::operator<(const fraction &right) const
{
	return compare(right) < 0;
}

bool fraction::operator<=(const fraction &right) const
{
	return compare(right) <= 0;
}

bool fraction::operator>(const fraction &right) const
{
	return compare(right) > 0;
}

bool fraction::operator>=(const fraction &right) const
{
	return compare(right) >= 0;
}

bool fraction::operator==(const fraction &right) const
{
	return compare(right) == 0;
}

// preincrement

fraction fraction::operator++()
{
	// a / b + 1 = a / b + b / b = (a + b) / b
	numerator += denominator;
	// return fraction(numerator, denominator);
	return *this;
}

fraction fraction::operator--()
{
	numerator -= denominator;
	return *this;
}

// post increment

fraction fraction::operator++(int unused)
{
	fraction clone(numerator, denominator); // copy of the current value
	numerator += denominator;
	return clone;
}

fraction fraction::operator--(int unsued)
{
	fraction clone(numerator, denominator); // copy of the current value
	numerator -= denominator;
	return clone;
}

// Non member functions

fraction operator+(int n, const fraction &right)
{
	int r_n = n * right.d() + right.n();
	int r_d = right.d();
	return fraction(r_n, r_d);
}

// cout

ostream &operator<<(ostream &out, const fraction &value)
{
	out << value.n() << "/" << value.d();
	return out;
}