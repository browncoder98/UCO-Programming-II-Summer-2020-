#pragma once
#include <string>
using namespace std;

class person
{
private:
	string name;
	int age;

public:
	person();
	person(string, int);
	~person(); //destructor
	string get_name() const;
	int get_age() const;
};