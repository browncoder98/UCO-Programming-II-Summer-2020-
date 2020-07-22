#include <iostream>
#include <cassert>
using namespace std;

void f2()
{
    cout << "========= f2() ==========" << endl;
    int a[5] = {0, 1, 2, 3, 4};

    assert(&a[0] == a);

    int *p;
    p = a; // p = &a[0];

    int *p2 = a;

    assert(*p == a[0]);

    for (int i = 0; i < 5; i++)
    {
        assert(a[i] == *p);
        ++p; // pointer arithmetic (only for + and -)
        assert(a[i] == *(p2 + i));
        assert(a[i] == *(a + i));
    }
}