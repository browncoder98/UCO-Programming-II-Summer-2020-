#include "question.h"

#include <iostream>
using namespace std;

question::question()
	: text(""), answer("") {}

void question::set_text(string text)
{
	this->text = text;
}

string question::get_text() const
{
	return text;
}

void question::set_answer(string answer)
{
	this->answer = answer;
}

bool question::check_answer(string response)
{
	return response == answer;
}

void question::display() const
{
	cout << text << endl;
}