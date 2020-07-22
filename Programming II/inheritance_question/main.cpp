#include "question.h"
#include "choice_question.h"
#include <iostream>
using namespace std;

int main()
{
	question q1;
	q1.set_text("What is the capitol of Oklahoma?");
	q1.set_answer("Oklahoma City");
	q1.display();

	string response;
	getline(cin, response);
	cout << boolalpha;
	cout << q1.check_answer(response) << endl;

	question q2;
	q2.set_text("Which language is used in Programming II class?");
	q2.set_answer("C++");
	q2.display();
	getline(cin, response);
	cout << q2.check_answer(response) << endl;

	choice_question q3;
	q3.set_text("Which programming language is not used in our department?");
	q3.add_choice("C++", false);
	q3.add_choice("Java", false);
	q3.add_choice("Fortran", true);
	q3.add_choice("C#", false);
	q3.add_choice("Javascript", false);

	q3.display();
	getline(cin, response);
	cout << q3.check_answer(response) << endl;

	//q2 = q3; // OK
	// q3 = q2; // ERROR sub = super

	question *pq = &q2;
	choice_question *pcq = &q3;

	//pcq = pq; // ERROR!
	pq = pcq; //OK!

	cout << endl
		 << endl;
	pq->display();

	cout << "-------------------------" << endl
		 << endl;
	question *quiz[4];
	quiz[0] = &q1;
	quiz[1] = &q2;
	quiz[2] = &q3;

	choice_question q4;
	q4.set_text("What is 2 + 3 = ?");
	q4.add_choice("1", false);
	q4.add_choice("2", false);
	q4.add_choice("3", false);
	q4.add_choice("5", true);
	quiz[3] = &q4;

	cout << "Quiz started!" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "Q" << (i + 1) << ": ";
		quiz[i]->display();
		getline(cin, response);
		cout << "Your answer is: " << quiz[i]->check_answer(response) << endl;
		cout << "------" << endl;
	}
}
