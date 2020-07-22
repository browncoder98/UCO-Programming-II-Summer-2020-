#include <iostream>
#include <cassert>
using namespace std;

void show(int *, int);

void f3()
{
    cout << "========== f3() ==========" << endl;

    int a[5] = {10, 20, 30, 70, 50};

    show(a, 5);
}

void show(int *p, int size)
{
    int b[5] = {10, 20, 30, 70, 50};
    for (int i = 0; i < size; i++)
    {
        assert(p[i] == b[i]);
    }
}