#pragma once
#include "stats.h"

class baseball
{

private:
	//variables
	int key;

	int user_input;

	int strike;

	int ball;

	bool won;
	int attempts;
	friend class stats;

public:
	//functions

	void create_key();

	void get_input();

	void match();
};