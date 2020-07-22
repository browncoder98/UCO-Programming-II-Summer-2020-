#include "baseball.h"
#include "wordguess.h"
#include "stats.h"
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
	cout << "Select a menu: ";
	int choice = -1;

	stats games;

	while (choice != 0)
	{

		cout << "\n1.) Baseball \n2.) Wordguess \n3.) Stats \n0.) Exit. \nChoice = ";
		cin >> choice;
		if (choice < 0 || choice > 3)
		{
			cout << "*** Invalid menu. Choose 0-3" << endl;
		}
		else if (choice == 1)
		{
			baseball b1;
			b1.create_key();

			games.increment_baseball_game();

			//return 0;
		}

		else if (choice == 2)
		{
			wordguess W;

			W.get_words();
			W.generate_random();
			W.get_guess();
			games.increment_word_game();
			//return 0;
		}
		else if (choice == 3)
		{

			if (games.wgames_played == 0 && games.bgames_played == 0)
			{
				cout << "No gameplay history" << endl;
			}
			else
			{

				cout << "Baseball Games: " << games.bgames_played << endl;
				cout << "WordGuess Games: " << games.wgames_played
					 << endl;
				cout << "Total games played: " << games.bgames_played + games.wgames_played << endl;
			}
		}
	}
}