#include <iostream>
#include "stats.h"
#include "baseball.h"
#include "wordguess.h"

using namespace std;

stats::stats()
{
	bgames_played = 0;
	wgames_played = 0;
}

void stats::increment_baseball_game()
{
	bgames_played++;
}

void stats::increment_word_game()
{
	wgames_played++;
}