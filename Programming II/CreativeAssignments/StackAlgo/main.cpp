/* Creative Assignment - 3: Infix to Prefix using Stacks */

/* Sample input -> Infix Expression: ((a+b)*c)
   Sample output -> Prefix: *+abc                         */

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
#include "stack.h"

int findprecedence(char ch) //Sorting out the order of precedence
{
	switch (ch)
	{
	case '+':
	case '-':

		return 1;
	case '*':
	case '/':
		return 2;
	}
	return 0;
}

int main()
{
	Stack s1; //Object declared
	int i, j = 0, k, l;
	char ch, temp;
	char infix[100], postfix[100], prefix[100];

	cout << "Enter an infix expression: " << endl;
	cin >> infix;
	i = 0;

	while (infix[i++] != '\0')
		;

	infix[i + 1] = '\0'; // Shifts by one position to the right
	infix[i--] = ')';

	while (i > 0)
	{
		infix[i] = infix[i - 1];
		i--;
	}
	infix[i] = '(';

	cout << infix << endl;

	l = strlen(infix);			  //Calculating the length of infix using 'strlen()'
	for (k = 0; k < (l / 2); k++) //Reversing infix using for loop
	{
		temp = infix[k];
		infix[k] = infix[l - k - 1];
		infix[l - k - 1] = temp;
	}

	cout << infix << endl;

	for (k = 0; k < l; k++)
	{
		if (infix[k] == '(')
		{
			infix[k] = ')';
		}
		else if (infix[k] == ')')
		{
			infix[k] = '(';
		}
	}
	cout << infix << endl;

	i = 0;
	while (infix[i] != '\0')
	{
		if (infix[i] == '(')
		{
			s1.push(infix[i]);
		}
		else if (infix[i] >= 'a' && infix[i] <= 'z')
		{
			postfix[j++] = infix[i];
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*')
		{
			while (s1.peep() == '+' || s1.peep() == '-' || s1.peep() == '*' || s1.peep() == '/') //Order of precedence determined with the help of peep()
			{
				if (findprecedence(s1.peep()) >= findprecedence(infix[i]))
				{
					postfix[j++] = s1.pop();
				}
				else
				{
					break;
				}
			}
			s1.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while ((ch = s1.pop()) != '(')
			{
				postfix[j++] = ch;
			}
		}
		i++;
	}
	postfix[j] = '\0'; //Appending the null character
	l = strlen(postfix);
	cout << "Postfix format - " << postfix << endl;

	for (k = 0; postfix[k] != '\0'; k++)
	{
		prefix[k] = postfix[l - k - 1];
	}
	prefix[k] = '\0';
	cout << "Prefix format - " << prefix << endl;
	return 0;
}