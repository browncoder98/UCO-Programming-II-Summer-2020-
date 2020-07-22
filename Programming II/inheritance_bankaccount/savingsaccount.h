#pragma once
#include "bankaccount.h"

class savingsaccount : public bankaccount
{
private:
	double int_rate;

public:
	savingsaccount(double);			// interest rate
	savingsaccount(double, double); // balance, interest rate
	virtual void end_of_month();
};