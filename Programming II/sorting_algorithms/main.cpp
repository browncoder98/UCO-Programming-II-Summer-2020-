#include <iostream>
#include <ctime>

using namespace std;
void selection_sort(int *, int);
void partition(int *, int, int);
void test_partition();
void test_quick_sort();
void quick_sort(int *, int);
void shuffle(int *, int);
double elapsed_time(void (*)(int *, int), int *, int);

int main()
{
	const int N = 100000;
	srand(time(nullptr));

	int data[N];
	for (int i = 0; i < N; i++)
	{
		data[i] = rand() % (N * 10);
	}

	for (int i = 1000; i < N; i *= 2)
	{
		shuffle(data, N);
		double t = elapsed_time(selection_sort, data, i);
		cout << "selection sort: " << i << " data: " << t << "secs" << endl;

		shuffle(data, N);
		t = elapsed_time(quick_sort, data, i);
		cout << "quick sort: " << i << " data: " << t << "secs" << endl;
	}
	/*test_partition();
	test_quick_sort();

	srand(time(nullptr));

	const int N = 100;
	const int RANGE = 100000;
	int data[N];
	for (int i = 0; i < N; i++)
	{
		data[i] = rand() % RANGE;
	}

	selection_sort(data, N);

	for (int i = 0; i < N; i++)
	{
		cout << data[i] << " ";
	}*/
}

double elapsed_time(void (*sort)(int *d, int s), int *data, int size)
{
	clock_t start = clock();
	sort(data, size);
	clock_t diff = clock() - start;

	return (double)diff / CLOCKS_PER_SEC;
}

void test_quick_sort()
{
	int data[] = {5, 10, 6, 2, 5, 9, 1, 3, 7, 4, 11, 12};
	quick_sort(data, 12);
}

void test_partition()
{
	int data[] = {4, 10, 6, 2, 5, 9, 1, 3, 7, 4, 11, 12};
	partition(data, 0, 11);
}