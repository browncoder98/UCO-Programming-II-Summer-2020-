#pragma once
#include "baseball.h"
#include "wordguess.h"
#include <list>

class stats

{

public:
    int bgames_played;

    int wgames_played;

    stats();

    void increment_baseball_game();

    void increment_word_game();
};