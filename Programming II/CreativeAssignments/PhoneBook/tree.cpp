#include "tree.h"
#include <iostream>
#include <fstream> // Stream class for both reading and writing onto files
#include <string.h>
using namespace std;
//ofstream outf; // Stream class to write on files

tree::tree()
{
	root = new node();
	root = NULL;
}

void tree::create() // creation of the nodes of the trees
{
	int k = 0;
	node *tmp, *p, *parent = NULL;
	tmp = root;
	p = new node();
	cout << "\nFirst Name: ";
	cin >> p->fname;
	cout << "\nLast Name: ";
	cin >> p->lname;
	do
	{
		cout << "\nPhone number: ";
		cin >> p->number;
		k = num_check(p->number);
	} while (k != 1);
	do
	{
		cout << "\nEmail-ID: ";
		cin >> p->email;
		k = email_check(p->email);
	} while (k != 1);
	p->left = NULL;
	p->right = NULL;
	if (root == NULL)
	{
		root = p;
	}
	else
	{
		while (tmp != NULL)
		{
			parent = tmp;
			if (strcmp(p->fname, tmp->fname) < 0)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		if (strcmp(p->fname, parent->fname) < 0)
			parent->left = p;
		else
			parent->right = p;
	}
}

int tree::num_check(long long int d) // Verifying whether the number occupies the given space or not
{
	int c = 0;
	while (d > 0)
	{
		c++;
		d /= 10;
	}
	if (c == 10)
		return 1;
	cout << "Number Invalid";
	return 0;
}

int tree::email_check(char a[]) // Verification for the proper email address
{
	int j = 0, i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == '@')
			j++;
		i++;
	}
	if (j == 1)
		return 1;
	cout << "Email id Invalid";
	return 0;
}

void tree::inorder() // Starting the inorder traversal for the binary search
{
	inordertrav(root);
}

void tree::inordertrav(node *t)
{

	if (t != NULL)
	{

		inordertrav(t->left);
		cout << "\nContact Details:\n";
		cout << "First name: " << t->fname << "\tLast name: " << t->lname << "\nPhone Number: " << t->number << "\tEmail id: " << t->email;
		inordertrav(t->right);
	}
}

void tree::search(node *root, char a[]) // For the searchhing the information stored within the nodes
{
	if (root)
	{
		if (strcmp(a, root->fname) < 0)
			search(root->left, a);
		else if (strcmp(a, root->fname) > 0)
			search(root->right, a);
		else
		{
			cout << "\nContact Details:\n";
			cout << "First name: " << root->fname << "\tLast name: " << root->lname << "\nPhone Number: " << root->number << "\tEmail id: " << root->email;
		}
	}
}

/*void tree::file_store(node *t) // For storing the details onto a text file
{
	if (t != NULL)
	{

		file_store(t->left);
		outf << "\nContact Details:\n"
			 << "First name: " << t->fname << "\tLast name: " << t->lname << "\nPhone Number: " << t->number << "\tEmail id: " << t->email;
		file_store(t->right);
	}
}*/
