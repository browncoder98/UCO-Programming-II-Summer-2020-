#include <iostream>
#include <string>
using namespace std;
#include "bankaccount.h"

int main()
{
    int n;
    bankaccount b1;

    n = 20;
    b1.set_id(2);
    b1.set_balance(250.25);

    cout << b1.get_id() << endl;
    cout << b1.get_balance() << endl;

    bankaccount b2;
    b2.set_id(4);
    cout << b2.get_id() << endl;
}