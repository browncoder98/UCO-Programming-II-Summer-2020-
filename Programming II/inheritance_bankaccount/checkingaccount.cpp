#include "checkingaccount.h"

int checkingaccount::MAX_FREE_TRANS = 5;
double checkingaccount::TRANS_FEE = 0.5;

checkingaccount::checkingaccount()
	: bankaccount(), no_trans(0)
{
}

checkingaccount::checkingaccount(double balance)
	: bankaccount(balance), no_trans(0)
{
}

int checkingaccount::get_ntrans() const
{
	return no_trans;
}

void checkingaccount::deposit(double amount)
{
	bankaccount::deposit(amount);
	++no_trans;
}

void checkingaccount::withdraw(double amount)
{
	bankaccount::withdraw(amount);
	++no_trans;
}

void checkingaccount::end_of_month()
{
	int excess_trans = no_trans - MAX_FREE_TRANS;
	if (excess_trans > 0)
	{
		double fee = excess_trans * TRANS_FEE;
		bankaccount::withdraw(fee);
	}
	no_trans = 0;
}