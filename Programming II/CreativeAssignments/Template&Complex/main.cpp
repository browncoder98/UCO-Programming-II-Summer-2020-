/* Creative Assignment -8: Implementing recursion with MiniMax Algorithm to create Tic Tac Toe with an AI opponent */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "tictactoe.h"
using namespace std;

void play(TicTacToe game, Player *x_player, Player *o_player)
{
	char letter = 'X';
	int index;
	game.reset();
	while (game.isMovePossible())
	{
		if (letter == 'O')
			index = o_player->getMove(game);
		else
			index = x_player->getMove(game);

		game.doMove(letter, index);
		cout << endl
			 << letter << " makes move to " << index + 1 << endl;
		game.printBoard();
		cout << endl;

		if (game.checkWinner(letter))
		{
			cout << endl
				 << letter << " wins !";
			return;
		}

		letter = (letter == 'X') ? 'O' : 'X';
	}
	cout << endl
		 << "Draw";
}

int main()
{
	TicTacToe game;

	char ch;
	int mode;

	HumanPlayer x_human('X');
	HumanPlayer o_human('O');
	ComputerAI x_AI('X');
	ComputerAI o_AI('O');

	Player *x, *o;

	do
	{
		cout << endl;
		cout << "Select game mode :" << endl
			 << "1. Human v/s Human" << endl
			 << "2. Human v/s Computer" << endl
			 << "3. Computer v/s Human" << endl
			 << "4. Computer v/s Computer" << endl
			 << endl
			 << "Mode : ";
		cin >> mode;

		switch (mode)
		{
		case 1:
			x = &x_human;
			o = &o_human;
			break;

		case 2:
			x = &x_human;
			o = &o_AI;
			break;

		case 3:
			x = &x_AI;
			o = &o_human;
			break;

		case 4:
			x = &x_AI;
			o = &o_AI;
			break;

		default:
			cout << "Wrong choice";
		}

		play(game, x, o);

		cout << endl
			 << "Play again (y/n) : ";
		cin >> ch;

	} while (ch == 'y' || ch == 'Y');

	return 0;
}
