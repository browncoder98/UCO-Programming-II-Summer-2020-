#pragma once

//abstract class cannot create an object
class bankaccount
{
private:
	double balance;

public:
	bankaccount();
	bankaccount(double); // balance
	double get_balance() const;
	void deposit(double);
	void withdraw(double);
	// pure (=0) virtual function
	virtual void end_of_month() = 0;
};