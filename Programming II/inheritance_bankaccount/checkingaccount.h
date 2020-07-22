#pragma once
#include "bankaccount.h"

class checkingaccount : public bankaccount
{
private:
	int no_trans; // # of transactions (deposit, withdraw)
	static int MAX_FREE_TRANS;
	static double TRANS_FEE;

public:
	checkingaccount();
	checkingaccount(double); // balance
	void deposit(double);
	void withdraw(double);
	int get_ntrans() const;
	virtual void end_of_month();
};