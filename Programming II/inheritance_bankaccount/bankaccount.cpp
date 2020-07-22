#include "bankaccount.h"
#include <iostream>
using namespace std;

bankaccount::bankaccount()
	: balance(0)
{
}

bankaccount::bankaccount(double b)
	: balance(b)
{
}

void bankaccount::deposit(double amount)
{
	balance += amount;
}

void bankaccount::withdraw(double amount)
{
	balance -= amount;
}

double bankaccount::get_balance() const
{
	return balance;
}

//void bankaccount::end_of_month()
//{
//	cout << "do not call me (bankaccount)" << endl;
//}