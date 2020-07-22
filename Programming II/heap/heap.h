#pragma once
#include <vector>
using namespace std;

class heap
{
private:
	vector<int> elements;
	int left_child_index(int) const;
	int right_child_index(int) const;
	int parent_index(int) const;
	int left_child_value(int) const;
	int right_child_value(int) const;
	int parent_value(int) const;
	void fix_heap();

public:
	heap();
	~heap();
	void push(int);
	int top() const;
	void pop();
	int size() const;
};