#include "heap.h"
#include <cassert>

using namespace std;

heap::heap()
{
	elements.push_back(0); // unused at index 0
}

heap::~heap() {}

int heap::top() const
{
	assert(size() > 0);
	return elements[1];
}

int heap::size() const
{
	return elements.size() - 1;
}

int heap::left_child_index(int index) const
{
	return 2 * index;
}

int heap::right_child_index(int index) const
{
	return 2 * index + 1;
}

int heap::parent_index(int index) const
{
	return index / 2;
}

int heap::left_child_value(int index) const
{
	return elements[2 * index];
}

int heap::right_child_value(int index) const
{
	return elements[2 * index + 1];
}

int heap::parent_value(int index) const
{
	return elements[index / 2];
}

void heap::push(int data)
{
	// add a new leaf
	elements.push_back(0);
	int index = elements.size() - 1;

	// demote parent of 'index' if the parent is smaller than new data
	while (index > 1 && parent_value(index) < data)
	{
		elements[index] = parent_value(index);
		index = parent_index(index);
	}

	// store the new data in the vacant slot
	elements[index] = data;
}

void heap::pop()
{
	int last = elements[elements.size() - 1];
	elements.pop_back();
	if (elements.size() == 1)
	{
		// empty heap
		return;
	}
	elements[1] = last;
	fix_heap();
}

// the last node (leaf) data is now at the root
// if root value is smaller than the child, then go down

void heap::fix_heap()
{
	int root = elements[1];
	int last_index = elements.size() - 1;

	//promote children of removed root if they are larger than the new root
	int index = 1;
	for (;;)
	{ // while (true)
		int child_index = left_child_index(index);
		if (child_index > last_index)

			break;

		int child = left_child_index(index); // value of the left child
		// see if right child is greater
		if (right_child_index(index) <= last_index && right_child_value(index) > child)
		{
			child_index = right_child_index(index);
			child = right_child_value(index);
		}

		if (child <= root)

			break;

		// promote child
		elements[index] = child;
		index = child_index;
	}
	// store root elements in vacant slot
	elements[index] = root;
}