#include "node.h"
#include <iostream>

using namespace std;

node::node(int d)
	: data(d), next(nullptr), prev(nullptr)
{
}
