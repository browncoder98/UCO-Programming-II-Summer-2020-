#include "baseball.h"

#include <iostream>

#include <time.h>

#include <stdlib.h>

using namespace std;

//creates the key
void baseball::create_key()
{

	srand(time(NULL));

	bool used[10];

	const int DIGITS = 3;

	int x = rand() % 10;

	used[x] = true;

	for (int i = 1; i < DIGITS; i++)
	{

		int digit = 0;

		do
		{

			digit = rand() % 10;

		} while (used[digit]);

		used[digit] = true;

		x *= 10;

		x += digit;
	}

	key = x;

	//if key is 2 digits (less than 100)

	if (key < 100)
	{
		key = key + 100;
		cout << "DEBUG: baseball key: " << key << endl;
	}
	else
		cout << "DEBUG: baseball key: " << key << endl;

	//attempts is initialized to 0
	attempts = 0;
	baseball::get_input();
}

//get inputs
void baseball::get_input()
{

	cout << "Play Baseball!!"
		 << "[" << attempts << "]" << endl;

	cin >> user_input;

	int guessed_number = user_input;

	int guessed_first_digit = guessed_number % 10;

	guessed_number /= 10;

	int guessed_second_digit = guessed_number % 10;

	guessed_number /= 10;

	int guessed_third_digit = guessed_number % 10;

	guessed_number /= 10;

	if (user_input < 0 || user_input > 999)
	{

		cout << "Invalid input. Must be between 0-999 with non repeating digits.";

		return;
	}
	else if (guessed_first_digit == guessed_second_digit || guessed_first_digit == guessed_third_digit || guessed_second_digit == guessed_third_digit)
	{

		cout << "Invalid input. Must be between 0-999 with non repeating digits.";

		return;
	}

	attempts++; //increase the attempt counts

	match();
}

//match
void baseball::match()
{
	int count = 0;

	int guessed_number = user_input;

	int actual_number = key;

	int guessed_first_digit, actual_first_digit;

	int guessed_second_digit, actual_second_digit;

	int guessed_third_digit, actual_third_digit;

	//if key is less than 100 (2 digits)
	if (key < 100)
		actual_first_digit = 0; //assign 1st digit to 0

	else
		actual_first_digit = actual_number % 10;

	guessed_first_digit = guessed_number % 10;

	guessed_number /= 10;

	actual_number /= 10;

	//2nd digit

	guessed_second_digit = guessed_number % 10;

	actual_second_digit = actual_number % 10;

	guessed_number /= 10;

	actual_number /= 10;

	//3rd digits
	guessed_third_digit = guessed_number % 10;

	actual_third_digit = actual_number % 10;

	guessed_number /= 10;

	actual_number /= 10;

	bool won = false;

	//if correct print the msg

	if (guessed_first_digit == actual_first_digit && guessed_second_digit == actual_second_digit && guessed_third_digit == actual_third_digit)
	{

		cout << "Correct!" << endl;
		cout << "No of attempts: " << attempts << endl;

		won = true;

		count = attempts;

		return;
	}

	//else print 'S'
	if (guessed_first_digit == actual_first_digit && guessed_second_digit == actual_second_digit ||

		guessed_first_digit == actual_first_digit && guessed_third_digit == actual_third_digit ||

		guessed_second_digit == actual_second_digit && guessed_third_digit == actual_third_digit)
	{

		strike = 2;

		cout << "S: " << strike << " ";

		int g_no = user_input;

		int u_no = key;

		int u_first = 0;

		int g_first = 0;

		int counter = 0;

		for (int i = 1; i <= 3; i++)
		{

			g_first = g_no % 10;

			g_no /= 10;

			for (int k = 1, u_no = key; k <= 3; k++)
			{

				u_first = u_no % 10;

				u_no /= 10;

				if (g_first == u_first)
				{

					counter++;
				}
			}
		}
		//prints 'B'

		cout << "B: " << counter << endl;
	}

	else if (guessed_first_digit == actual_first_digit || guessed_second_digit == actual_second_digit ||

			 guessed_third_digit == actual_third_digit)
	{

		strike = 1;

		cout << "S: " << strike << " ";

		int g_no = user_input;

		int u_no = key;

		int u_first = 0;

		int g_first = 0;

		int counter = 0;

		for (int i = 1; i <= 3; i++)
		{

			g_first = g_no % 10;

			g_no /= 10;

			for (int k = 1, u_no = key; k <= 3; k++)
			{

				u_first = u_no % 10;

				u_no /= 10;

				if (g_first == u_first)
				{

					counter++;
				}
			}
		}

		cout << "B: " << counter << endl;
	}
	else
	{

		strike = 0;

		cout << "S: " << strike << " ";

		int g_no = user_input;

		int u_no = key;

		int u_first = 0;

		int g_first = 0;

		int counter = 0;

		for (int i = 1; i <= 3; i++)
		{

			g_first = g_no % 10;

			g_no /= 10;

			for (int k = 1, u_no = key; k <= 3; k++)
			{

				u_first = u_no % 10;

				u_no /= 10;

				if (g_first == u_first)
				{

					counter++;
				}
			}
		}

		cout << "B: " << counter << endl;
	}
	//call the input if guess is not correct
	get_input();
	return;
}
