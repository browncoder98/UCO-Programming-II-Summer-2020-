#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

void swap(int &, int &);
void qsort(int *, int, int);
int partition(int *, int, int);
void shuffle(int *, int);

void quick_sort(int *data, int size)
{
	shuffle(data, size);
	qsort(data, 0, size - 1);
}

void qsort(int *data, int lo, int hi)
{
	if (hi <= lo)
		return;
	int k = partition(data, lo, hi);
	qsort(data, lo, k - 1);
	qsort(data, k + 1, hi);
}

int partition(int *data, int lo, int hi)
{
	int i = lo;		// from left
	int k = hi + 1; // from right
	for (;;)
	{
		// find item on left to swap
		while (data[++i] < data[lo])
		{
			if (i == hi)
				break;
		}
		// find item on right to swap
		while (data[lo] < data[--k])
		{
			if (k == lo)
				break;
		}
		// check if i and k cross
		if (i >= k)
			break;
		swap(data[i], data[k]);
	}
	// place the key data[lo] in the right place
	swap(data[lo], data[k]);
	return k; // partition index
}

void swap(int &i, int &k)
{
	int temp = i;
	i = k;
	k = temp;
}

void shuffle(int *data, int size)
{
	srand(time(nullptr)); // randomize seed
	for (int i = 1; i < size; i++)
	{
		// 0 <= r <= i
		int r = rand() % (i + 1);
		swap(data[i], data[r]);
	}
}