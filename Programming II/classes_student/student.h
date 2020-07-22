#pragma once

#include <string>
using namespace std;

class student
{
private:
	int id;
	double gpa;
	string name;

public:
	student(); // default Constructor
	student(int, double, string);
	int get_id() const;
	double get_gpa() const;
	string get_name() const;
	void set_gpa(double);
};