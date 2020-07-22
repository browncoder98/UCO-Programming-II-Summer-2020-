#include "wordguess.h"

#include <iostream>

#include <fstream>

#include <string>

#include <vector>

#include <time.h>

#include <stdlib.h>

#include <set>

using namespace std;

void wordguess::get_words()
{

	ifstream in("wordpool.txt");

	string str;

	while (getline(in, str))
	{

		if (str.size() > 0)
		{

			string_vector.push_back(str);
		}
	}

	in.close();
}

void wordguess::generate_random()
{

	srand(time(0));

	int r = string_vector.size() - 1;

	int random = rand() % (r + 1);

	random_word = string_vector[random];

	cout << "Debug: key = " << random_word << endl;
}

void wordguess::get_guess()
{

	wattempts = 1;

	char input;

	string user_guess = "";

	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	string used = "";

	int correct = 0;

	for (int i = 0; i < random_word.length() - 1; i++)
	{

		user_guess = user_guess + ".";
	}

	while (1)
	{

		cout << "[" << wattempts << "] "
			 << "[" << user_guess << "] "
			 << "Choose: "
			 << "[" << alphabet << "] ";

		cin >> input;

		cout << endl;

		set<char> unused(alphabet.begin(), alphabet.end());

		if (!isalpha(input))
		{

			cout << "Must be a letter" << endl;
		}
		else if (unused.find(input) == unused.end())
		{

			cout << "The letter has already been used." << endl;
		}
		else
		{

			unused.erase(input);

			for (int i = 0; i < random_word.length() - 1; i++)
			{

				if (random_word.at(i) == input)
				{

					correct++;

					string s(1, input);

					user_guess.replace(i, 1, s);
				}
			}

			alphabet.replace(input - 97, 1, ".");

			if (correct == random_word.length() - 1)
			{

				cout << "Word is: " << random_word << endl;

				cout << "Made correct guess in " << wattempts << " attempts" << endl;

				break;
			}
		}

		wattempts++;
	}
}
