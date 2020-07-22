#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	const int K = 1000;	  // Kilo
	const int N = 16 * K; //
	const int RANGE = 10000;
	// rand() -> 0 ~ MAX_INT

	srand(time(nullptr));

	/*cout << "How many thousands of data? : ";
	int n;
	cin >> n;

	cout << "Data filename? (no blank) :";
	string filename;
	cin >> filename;

	ofstream datafile;
	datafile.open(filename.c_str());

	int size = n * K;*/
	for (int i = 0; i < N; i++)
	{
		cout << rand() % RANGE - RANGE / 2 << " ";
		if (i % 10 == 0)
			cout << endl;
	}
	cout << endl;
}

/*datafile.close();

int pcount = 0, ncount = 0;
ifstream infile;
infile.open(filename.c_str());
int data;
while (infile >> data)
{
	if (data < 0)
		ncount++;
	else
		pcount++;
}
infile.close();
cout << "Positive or zero: count = " << pcount << endl;
cout << "Negative        : count = " << ncount << endl;
cout << "Total: " << pcount + ncount << endl;
}*/