#pragma once
#include "stats.h"

#include <vector>

#include <string>

using namespace std;

class wordguess
{

private:
	int wattempts;

	int location;

	string random_word;

	vector<string> string_vector;

	friend class stats;

public:
	void get_words();

	void generate_random();

	void get_guess();
};