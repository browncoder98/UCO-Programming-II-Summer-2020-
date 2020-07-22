#include <iostream>
#include <cassert>

using namespace std;
void f1()
{
    cout << "========== f1() ===========" << endl;

    int p;
    double d = 3.14;
    char c = 'A';
    bool b = false;

    p = 10;
    assert(p == 10);

    //how to get the address of a variable

    int *x; // a pointer variable (variable)
    x = &p;
    // cout << x << endl;

    *x = 20; // dereference operator
    assert(p == 20);

    int *y;
    y = x;
    *y = 30;

    double *x2;
    x2 = &d;
    assert(d == *x2);
    *x2 = 5.01;
    assert(d == 5.01);

    char *x3;
    x3 = &c;
    assert(*x3 == 'A');
}
