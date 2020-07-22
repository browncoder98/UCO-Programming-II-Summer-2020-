#include "choice_question.h"
#include <iostream>
using namespace std;

choice_question::choice_question() {}

void choice_question::add_choice(string choice, bool correct)
{
	choices.push_back(choice);
	if (correct)
	{
		int choice_index = choices.size();
		string choice_string = to_string(choice_index);
		question::set_answer(choice_string);
	}
}

void choice_question::display() const
{
	cout << get_text() << endl;
	for (int i = 0; i < choices.size(); i++)
	{
		cout << i + 1 << " " << choices[i] << endl;
	}
}