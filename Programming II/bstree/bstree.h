#pragma once
#include "node.h"

class bstree
{
private:
	node *rootp;
	node *insert(node *, int);
	void print(node *) const;
	int find_min(node *) const;
	node *erase(node *, int);
	int node_count(node *) const;
	int leaf_count(node *) const;
	int layer_count(node *) const;
	void inorder(node *, void (*)(int)) const;
	void preorder(node *) const;
	void postorder(node *) const;

public:
	bstree();
	~bstree();
	void insert(int);
	void print() const;
	int find_min() const;
	void erase(int);
	int node_count() const;
	int leaf_count() const;
	int layer_count() const;
	int height() const;
	void inorder(void (*)(int)) const;
	void preorder() const;
	void postorder() const;
	void breadth_first() const;
};