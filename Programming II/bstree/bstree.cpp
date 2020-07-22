#include "bstree.h"
#include <cassert>
#include <queue>
#include <iostream>
using namespace std;

bstree::bstree() : rootp(nullptr) {}

bstree::~bstree()
{
	if (rootp == nullptr)
	{
		return;
	}

	queue<node *> q;
	q.push(rootp);

	while (!q.empty())
	{
		node *r = q.front();
		q.pop();
		if (r->left != nullptr)
		{
			q.push(r->left);
		}
		if (r->right != nullptr)
		{
			q.push(r->right);
		}
		delete r;
	}
}

void bstree::breadth_first() const
{
	if (rootp == nullptr)
	{
		return;
	}

	queue<node *> q;
	q.push(rootp);

	while (!q.empty())
	{
		node *r = q.front();
		q.pop();
		if (r->left != nullptr)
		{
			q.push(r->left);
		}
		if (r->right != nullptr)
		{
			q.push(r->right);
		}
		cout << r->data << " ";
	}
}

void bstree::insert(int data)
{
	rootp = insert(rootp, data);
}

node *bstree::insert(node *r, int data)
{
	if (r == nullptr)
	{
		r = new node(data);
	}
	else if (data < r->data)
	{
		r->left = insert(r->left, data);
	}
	else if (data > r->data)
	{
		r->right = insert(r->right, data);
	}
	else
	{
		// data == r->data;
		// BST: assume unique data only (SET)
	}

	return r;
}

void bstree::print() const
{
	print(rootp);
}

void bstree::print(node *r) const
{
	if (r == nullptr)
	{
		return;
	}
	cout << r->data << " => ";

	if (r->left == nullptr)
	{
		cout << "(empty)";
	}
	else
	{
		cout << "(" << r->left->data << ")";
	}
	if (r->right == nullptr)
	{
		cout << "(empty)" << endl;
	}
	else
	{
		cout << "(" << r->right->data << ")" << endl;
	}

	if (r->left != nullptr)
	{
		print(r->left);
	}
	if (r->right != nullptr)
	{
		print(r->right);
	}
}

int bstree::find_min() const
{
	return find_min(rootp);
}

int bstree::find_min(node *r) const
{
	assert(r != nullptr);
	if (r->left == nullptr)
	{
		return r->data;
	}
	else
	{
		return find_min(r->left);
	}
}

void bstree::erase(int data)
{
	assert(rootp != nullptr);
	rootp = erase(rootp, data);
}

node *bstree::erase(node *r, int data)
{
	if (r == nullptr)
	{
		return nullptr;
	}
	if (data < r->data)
	{
		r->left = erase(r->left, data);
	}
	else if (data > r->data)
	{
		r->right = erase(r->right, data);
	}
	else
	{
		//data == r->data;
		if (r->left != nullptr && r->right != nullptr)
		{ // both L and R subtrees exist
			int mindata = find_min(r->right);
			r->data = mindata;
			r->right = erase(r->right, mindata);
		}
		else
		{
			//	only one subtree OR no subtree
			node *discard = r;
			r = (r->left != nullptr) ? r->left : r->right;
			delete discard;
		}
	}
	return r;
}

int bstree::node_count() const
{
	return node_count(rootp);
}

int bstree::node_count(node *r) const
{
	if (r == nullptr)
	{
		return 0;
	}
	else
	{
		return node_count(r->left) + node_count(r->right) + 1;
	}
}

int bstree::leaf_count() const
{
	return leaf_count(rootp);
}

int bstree::leaf_count(node *r) const
{
	if (r == nullptr)
	{
		return 0;
	}
	else if (r->left == nullptr && r->right == nullptr)
	{
		return 1;
	}
	else
	{
		return leaf_count(r->left) + leaf_count(r->right);
	}
}

int bstree::layer_count() const
{
	return layer_count(rootp);
}

int bstree::layer_count(node *r) const
{
	if (r == nullptr)
	{
		return 0;
	}
	else if (r->left == nullptr && r->right == nullptr)
	{
		return 1;
	}
	else
	{
		int ll = layer_count(r->left);
		int lr = layer_count(r->right);
		return ll > lr ? ll + 1 : lr + 1;
	}
}

int bstree::height() const
{
	assert(rootp != nullptr);
	return layer_count(rootp) - 1;
}

void bstree::inorder(void (*f)(int)) const
{
	inorder(rootp, f);
}

void bstree::inorder(node *r, void (*f)(int)) const
{
	if (r == nullptr)
	{
		return;
	}
	inorder(r->left, f); // L
	// cout << r->data << " "; // V
	(*f)(r->data);
	inorder(r->right, f); // R
}

void bstree::preorder() const
{
	preorder(rootp);
}

void bstree::preorder(node *r) const
{
	if (r == nullptr)
	{
		return;
	}
	cout << r->data << " "; // V
	preorder(r->left);		// L
	preorder(r->right);		// R
}

void bstree::postorder() const
{
	postorder(rootp);
}

void bstree::postorder(node *r) const
{
	if (r == nullptr)
	{
		return;
	}

	postorder(r->left);		// L
	postorder(r->right);	// R
	cout << r->data << " "; // V
}