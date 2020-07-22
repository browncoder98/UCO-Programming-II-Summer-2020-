#include <iostream>
#include <cassert>
using namespace std;
void f4()
{
    cout << "===== f4() =====" << endl;

    int n;

    int *p = new int;

    *p = 20;
    *p = *p + 2;
    assert(*p == 22);
    delete p;

    double *d = new double;
    *d = 1.5;
    delete d;
}