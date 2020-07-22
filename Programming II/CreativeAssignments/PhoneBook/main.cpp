/*Creative Assignment 9 : Implementing Binary Search Tree to create, edit update and delete information in a contact list */

#include <iostream>
#include <fstream> // Stream class for both reading and writing onto files
#include <string.h>
#include "tree.h"
using namespace std;
ofstream outf; // Stream class to write on files

int main()
{
	tree q;
	char c, a[20];
	int x;
	cout << "\n#Phone Directory using BST\nEnter contacts for Phone book creation:\n";
	do
	{
		cout << "\nEnter the Contact Details:\n";
		q.create();
		cout << "\nContinue?";
		cin >> c;
	} while (c == 'y');
	cout << "\nCreation Successful\n";
	do
	{
		cout << "Enter the choice :\n1.Insert\t2.Delete\t3.Edit\t4.Search\t5.Print Phone book ?\n";
		cin >> x;
		switch (x)
		{
		case 1:
			q.create();
			cout << "\nContact Insertion successful";
			break;
		case 2:
			cout << "\nEnter the First name:";
			cin >> a;
			q.root = q.deleteNode(q.root, a);
			cout << "\n1 Contact deleted successfully";
			break;
		case 3:
			cout << "\nEnter the First name:";
			cin >> a;
			q.root = q.edit(q.root, a);
			cout << "\nChanges updated";
			break;
		case 4:
			cout << "\nEnter the First name:";
			cin >> a;
			q.search(q.root, a);
			break;
		case 5:
			q.inorder();
			break;
		default:
			cout << "\nOption Invalid";
		}
		//outf.open("Contacts.txt", ios::trunc); // Conversion of file to txt format
		//q.file_store(q.root);
		cout << " Continue?\n";
		cin >> c;
	} while (c == 'y');

	//outf.close();
	cout << " *** PROGRAM HAS TERMINATED *** " << endl;
	return 0;
	exit(0);
}