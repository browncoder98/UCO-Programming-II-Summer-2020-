#include "bankaccount.h"

void bankaccount::set_id(int n)
{
    id = n;
}
int bankaccount::get_id()
{
    return id;
}
double bankaccount::get_balance()
{
    return balance;
}
void bankaccount::set_balance(double b)
{
    balance = b;
}