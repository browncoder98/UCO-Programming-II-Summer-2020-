#include <iostream>
#include <ctime>
#include "tictactoe.h"
using namespace std;

TicTacToe::TicTacToe()
{
	reset();
}

void TicTacToe::resetBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			board[i][j] = ' ';
	}
}

void TicTacToe::resetWinner()
{
	winner = ' ';
}

void TicTacToe::reset()
{
	resetBoard();
	resetWinner();
}

void TicTacToe::setChar(char symbol, int i)
{
	board[i / 3][i % 3] = symbol;
}

void TicTacToe::setChar(char symbol, int i, int j)
{
	board[i][j] = symbol;
}

char TicTacToe::getChar(int i)
{
	return board[i / 3][i % 3];
}

char TicTacToe::getChar(int i, int j)
{
	return board[i][j];
}

char TicTacToe::whoWon()
{
	return winner;
}

bool TicTacToe::isMovePossible()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
				return true;
		}
	}
	return false;
}

vector<int> TicTacToe::allPossibleMoves()
{
	vector<int> move_set;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
				move_set.push_back(3 * i + j);
		}
	}
	return move_set;
}

// check winner
bool TicTacToe::checkWinner(char symbol)
{
	// horizontal check
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == symbol)
			return true;
	}

	// vertical check
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == symbol)
			return true;
	}

	// diagonal 1 check
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == symbol)
		return true;

	// diagonal 2 check
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == symbol)
		return true;

	return false;
}

void TicTacToe::doMove(char symbol, int index)
{
	int i = index / 3, j = index % 3;
	board[i][j] = symbol;

	if (checkWinner(symbol))
		winner = symbol;
}

void TicTacToe::printBoard()
{
	for (int i = 0; i <= 6; i += 3)
	{
		cout << "\n " << getChar(i) << " | " << getChar(i + 1) << " | " << getChar(i + 2);
	}
}

Player::Player(char s)
{
	symbol = s;
}

char Player::getSymbol()
{
	return symbol;
}

HumanPlayer::HumanPlayer(char s) : Player(s){};

int HumanPlayer::getMove(TicTacToe game)
{
	int index;
	while (1)
	{
		cout << "\nEnter index: ";
		cin >> index;

		if (game.getChar(index - 1) == ' ')
			return index - 1;

		cout << "Wrong Move";
	}
}

ComputerAI::ComputerAI(char s) : Player(s) {}

int ComputerAI::getMove(TicTacToe game)
{
	ttt_move move;
	srand(time(0));

	if (game.allPossibleMoves().size() == 9)
		move.index = rand() % 9;
	else
		move = minimax(game, getSymbol());

	return move.index;
}

ttt_move ComputerAI::minimax(TicTacToe state, char curr_player)
{
	char max_player = this->getSymbol();
	char other_player = (curr_player == 'X') ? 'O' : 'X';
	ttt_move best, current;

	// base condition for win - lose
	if (state.whoWon() == other_player)
	{
		best.score = state.allPossibleMoves().size() + 1;
		if (other_player != max_player)
			best.score = -best.score;
		return best;
	}
	// base condtion for draw
	if (!state.isMovePossible())
	{
		best.score = 0;
		return best;
	}

	if (curr_player == max_player)
		best.score = -1000000;
	else
		best.score = 1000000;

	vector<int> move_set = state.allPossibleMoves();

	for (int i = 0; i < move_set.size(); i++)
	{
		state.doMove(curr_player, move_set[i]);
		current = minimax(state, other_player);
		state.setChar(' ', move_set[i]);
		state.resetWinner();
		current.index = move_set[i];

		if (curr_player == max_player)
		{
			if (current.score > best.score)
				best = current;
		}
		else
		{
			if (current.score < best.score)
				best = current;
		}
	}
	return best;
}
