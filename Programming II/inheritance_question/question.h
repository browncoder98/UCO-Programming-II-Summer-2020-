#pragma once
#include <string>

using namespace std;

class question
{
private:
	string text; // question text
	string answer;

public:
	question();
	void set_text(string);
	string get_text() const;
	void set_answer(string);
	bool check_answer(string);
	virtual void display() const;
};