#pragma once
#include <iostream>
#include <fstream> // Stream class for both reading and writing onto files
#include <string.h>
using namespace std;
//ofstream outf; // Stream class to write on files
class node
{

	long long int number;
	char fname[20], lname[20], email[40];
	node *left, *right;
	friend class tree;
};

class tree
{

public:
	node *root;
	tree();							// default constructor
	void create();					// creation of the nodes of the trees
	int num_check(long long int d); // Verifying whether the number occupies the given space or not
	int email_check(char a[]);		// Verification for the proper email address
	void inorder();					// Starting the inorder traversal for the binary
	void inordertrav(node *t);
	node *minValueNode(struct node *l) // for finding the least value on the left most node
	{
		node *current = l;

		/* loop down to find the leftmost leaf */
		while (current->left != NULL)
			current = current->left;

		return current;
	}
	node *deleteNode(struct node *root, char a[20]) // for the deletion of the required nodes
	{

		if (root == NULL)
			return root;

		if (strcmp(a, root->fname) < 0)
			root->left = deleteNode(root->left, a);

		else if (strcmp(a, root->fname) > 0)
			root->right = deleteNode(root->right, a);

		else
		{

			if (root->left == NULL)
			{
				node *temp = root->right;
				return temp;
			}
			else if (root->right == NULL)
			{
				node *temp = root->left;
				return temp;
			}

			node *temp = minValueNode(root->right);
			root->number = temp->number;
			strcpy(root->lname, temp->lname);
			strcpy(root->fname, temp->fname);
			strcpy(root->email, temp->email);
			root->right = deleteNode(root->right, temp->fname);
		}
		return root;
	}
	node *edit(node *root, char a[]) // For editing the info with the help of binary tree search algorithm
	{
		if (root == NULL)
			return root;

		if (strcmp(a, root->fname) < 0)
			root->left = edit(root->left, a);

		else if (strcmp(a, root->fname) > 0)
			root->right = edit(root->right, a);
		else
		{
			int x;
			cout << "Enter the data choice to edit:\n1.First name\t2.Last name\t3.Phone number\t4.Email id:\n";
			cin >> x;
			cout << "\nEnter the new value:";
			switch (x)
			{
			case 1:
				cin >> root->fname;
				break;
			case 2:
				cin >> root->lname;
				break;
			case 3:
				cin >> root->number;
				break;
			case 4:
				cin >> root->email;
				break;
			default:
				cout << "Value not modifed";
			}
		}
		return root;
	}
	void search(node *root, char a[]); // For the searchhing the information stored within the nodes
	void file_store(node *t);		   // For storing the details onto a text file
};