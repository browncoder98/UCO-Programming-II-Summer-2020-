#pragma once
#include <vector>
using namespace std;

class TicTacToe
{
	char board[3][3];
	char winner;

public:
	// constructor
	TicTacToe();
	void resetBoard();
	void resetWinner();
	void reset();
	// setters and getters
	void setChar(char symbol, int i);
	void setChar(char symbol, int i, int j);
	char getChar(int i);
	char getChar(int i, int j);
	char whoWon();
	// possible moves
	bool isMovePossible();
	vector<int> allPossibleMoves();
	// check winner
	bool checkWinner(char symbol);
	// do move
	void doMove(char symbol, int index);
	void printBoard();
};

class Player // abstract class
{
	char symbol;

public:
	// constructor
	Player(char s);
	// getter
	char getSymbol();
	// virtual function
	virtual int getMove(TicTacToe game) = 0;
};

class HumanPlayer : public Player // class to take input from user
{
public:
	//constructor
	HumanPlayer(char s);
	// getMove() over-ride
	int getMove(TicTacToe game);
};

struct ttt_move
{
	int index;
	long score;
};

class ComputerAI : public Player
{
public:
	// constructor
	ComputerAI(char s);
	// getMove() over-ride
	int getMove(TicTacToe game);
	// minimax
	ttt_move minimax(TicTacToe state, char curr_player);
};
