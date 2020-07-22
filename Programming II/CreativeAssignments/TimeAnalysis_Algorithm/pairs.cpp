/* Creative Assignment - 12 : Run time analysis of the algorithm for finding all pairs possible in a given array */
// Time Complexity: O(N^2)
// Input: arr[] = {1, 2}
//Output: Output: (1, 1), (1, 2), (2, 1), (2, 2).

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "Usage: " << argv[0] << "datafile" << endl;
		return 1;
	}
	ifstream infile(argv[1]);
	if (infile.fail())
	{
		cout << "Cannot open " << argv[1] << endl;
		return 1;
	}

	vector<int> vdata;
	int n;
	while (infile >> n)
	{
		vdata.push_back(n);
	}

	// convert vector to int array for faster computing
	int *data = vdata.data();
	int N = vdata.size();

	// Nested loop for all possible pairs
	int count = 0;

	clock_t start = clock();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//cout << "(" << data[i] << ", "
			//<< data[j] << ")"
			//<< ", ";
			++count;
		}
	}

	clock_t diff = clock() - start;

	cout << "Count is " << count << endl;
	cout << "It took " << diff << " clock ticks";
	cout << "       " << (float)diff / CLOCKS_PER_SEC << " secs" << endl;

	// cout << "Count is " << count << endl;
}