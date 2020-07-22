#pragma once
#include "question.h"
#include <vector>
using namespace std;

class choice_question : public question
{
private:
	vector<string> choices;

public:
	choice_question();
	void add_choice(string, bool);
	virtual void display() const; // function overriding
};
