#include <iostream>
#include <cassert>
using namespace std;

void show2(int *, int);

void f5()
{
    cout << "========== f5() ==========" << endl;

    int *p;
    p = new int[5];

    for (int i = 0; i < 5; i++)
    {
        p[i] = i + 10;
    }

    int test[5] = {10, 11, 12, 13, 14};

    for (int i = 0; i < 5; i++)
    {
        assert(p[i] == test[i]);
    }

    show2(p, 5);

    delete[] p;
}

void show2(int *array, int size)
{
    int test[5] = {10, 11, 12, 13, 14};
    for (int i = 0; i < size; i++)
    {
        assert(array[i] = test[i]);
    }
}