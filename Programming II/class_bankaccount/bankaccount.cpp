#include "bankaccount.h"

int bankaccount::id_gen = 0;

bankaccount::bankaccount()
	: balance(0), owner("no name", -1), pjoint_owner(nullptr)
{
	//owner = person("John", 29);
	id = id_gen++;
}

bankaccount::bankaccount(double b) : balance(b), id(-1), owner("no name", -1), pjoint_owner(nullptr)
{
	id = id_gen++;
}

bankaccount::bankaccount(string name, int age)
	: balance(0), owner(name, age), pjoint_owner(nullptr)
{
	id = id_gen++;
}

bankaccount::~bankaccount()
{
	delete pjoint_owner;
}

int bankaccount::get_id() const
{
	return id;
}

void bankaccount::deposit(double amt)
{
	balance += amt;
}

void bankaccount ::withdraw(double amt)
{
	balance -= amt;
}

double bankaccount::get_balance() const
{
	return balance;
}

void bankaccount::set_jointowner(string name, int age)
{
	if (pjoint_owner != nullptr)
	{
		delete pjoint_owner;
	}
	pjoint_owner = new person(name, age);
}