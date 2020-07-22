#pragma once

class student
{
private:
	float gpa;
	int id;
	static int count;

public:
	student();
	student(float);
	student(int);
	student(float, int);
	~student();
	void set_gpa(float);
	void set_id(int);
	static int get_count();

	class out_of_range_gpa
	{
	}; // empty inner class
	class invalid_id
	{
	};
};