#include "savingsaccount.h"

savingsaccount::savingsaccount(double r)
	: int_rate(r)
{
}

savingsaccount::savingsaccount(double balance, double r)
	: bankaccount(balance), int_rate(r)
{
}

void savingsaccount::end_of_month()
{
	double interest = bankaccount::get_balance() * int_rate;
	bankaccount::deposit(interest);
}