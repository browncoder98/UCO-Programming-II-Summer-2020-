#include "tstack.h"
#include "tarray.h"
#include "person.h"

int main()
{
	tstack<int> s1;
	s1.push(5);
	s1.push(6);

	tstack<double> s2;
	s2.push(1.2);
	s2.push(9.7);

	tarray<int> arr(5);
	tarray<double> arr2(5);

	// tarray test
	tarray<double> d(10);

	d.set(0, 0.5);
	d.set(1, 1.5);
	d.set(2, 2.5);

	double t = d.get(0);
	t = d.get(1);
	t = d.get(2);

	arr.set(0, 10);
	arr.set(1, 20);
	arr.set(2, 30);

	int n = arr.get(0);
	n = arr.get(1);
	n = arr.get(2);

	tarray<double> m1(5), m2(5);
	m1[0] = 4.5;
	m1[1] = 5.5;
	m2[0] = 2.5;
	m2[1] = 3.5;

	tarray<double> m3(5);
	m3 = m1 + m2; // m3 = m1.operator+(m2);

	m3 = m1 + 0.1;
	m3 = 0.3 + m1;

	//person
	tarray<person> pp(3);
	person p1("John", 23);
	person p2("Mary", 23);
	pp[0] = p1;
	pp[1] = p2;

	tarray<person> pp2(3);
	pp2[0] = person("Kelly", 19);
	pp2[1] = person("Sue", 29);

	tarray<person> pp3(3);
	pp3 = pp + pp2;
}