//This program initializes the classes' constructors and methods.
#include "rps.h"
#include <iostream>

using namespace std;
// Initialized default Tool constructor
Tool::Tool()
{
	strength = 1;
	type = 's';
}

Tool::Tool(int newStrength, char newType)
{
	strength = newStrength;
	type = newType;
}

// Initialized default Rock constructor
Rock::Rock()
{
	strength = 1;
	type = 'r';
}

// Initialized default Paper constructor
Paper::Paper()
{
	strength = 1;
	type = 'p';
}

// Initialized default Scissors constructor
Scissors::Scissors()
{
	strength = 1;
	type = 'p';
}

// Initialized Rock constructor
Rock::Rock(int r)
{
	strength = r;
	type = 'r';
}

// Initialized Paper constructor
Paper::Paper(int p)
{
	strength = p;
	type = 'p';
}

// Initialized Scissors constructor
Scissors::Scissors(int s)
{
	strength = s;
	type = 's';
}

// Initialized fight method for Rock class
bool Rock::fight(Tool opponent)
{
	if (opponent.getType() == 's')
	{
		strength *= 2;
	}
	else if (opponent.getType() == 'p')
	{
		strength *= 0.5;
	}
	else
	{
		strength;
	}

	if (strength > opponent.getStrength())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Initialized fight method for Paper class
bool Paper::fight(Tool opponent)
{
	if (opponent.getType() == 'r')
	{
		strength *= 2;
	}
	else if (opponent.getType() == 's')
	{
		strength *= 0.5;
	}
	else
	{
		strength;
	}

	if (strength > opponent.getStrength())
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Initialized fight method for Scissors class
bool Scissors::fight(Tool opponent)
{
	if (opponent.getType() == 's')
	{
		strength *= 2;
	}
	else if (opponent.getType() == 'r')
	{
		strength *= 0.5;
	}
	else
	{
		strength;
	}

	if (strength > opponent.getStrength())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Returns Tool strength
int Tool::getStrength()
{
	return strength;
}

// Initializes strength to new strength (s)
void Tool::setStrength(int s)
{
	strength = s;
}

// Returns Tool type
char Tool::getType()
{
	return type;
}

// Initializes type to new type (t)
void Tool::setType(char t)
{
	type = t;
}

// Function to check who won between two objects (Rock, Paper, or Scissors)
void checkWinner(bool win, Tool a, Tool b)
{
	if (win == true)
	{
		switch (a.getType())
		{
		case 'r':
			cout << "Rock wins!" << endl;
			break;
		case 'p':
			cout << "Paper wins!" << endl;
			break;
		case 's':
			cout << "Scissors wins!" << endl;
			break;
		default:
			cout << "Something went wrong" << endl;
		}
	}
	else
	{
		switch (b.getType())
		{
		case 'r':
			cout << "Rock wins!" << endl;
			break;
		case 'p':
			cout << "Paper wins!" << endl;
			break;
		case 's':
			cout << "Scissors wins!" << endl;
			break;
		default:
			cout << "Something went wrong" << endl;
		}
	}
}