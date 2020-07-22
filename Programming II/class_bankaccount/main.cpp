#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

#include "bankaccount.h"

// TDD: test driven development

int main()
{
	const double E = 0.000001;

	bankaccount b1;
	assert(b1.get_id() == 0);

	bankaccount b2;
	assert(b2.get_id() == 1);
	assert(b2.get_balance() == 0);

	double amt = 0.0;
	for (int i = 0; i < 10; i++)
	{
		amt += 0.01;
	} // amt = 0.1
	b1.deposit(amt);
	double diff = fabs(b1.get_balance() - 0.1);
	assert(diff < E);

	//bankaccount b2(1000);
	//bankaccount b3("Mary", 19);

	//b1.set_jointowner("Jointname", 43);
}
