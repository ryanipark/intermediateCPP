//************************************
// inpost.cpp
//
// CSCI Assignment 7
// by Ryan Park z1940877
//
//************************************

#include <iostream>
#include <cctype>
#include <string>

#include "inpost.h"
#include "mystack.h"

using namespace std;


/* Function converts string input(infix) to postfix
 *  
 * @param refrence to const string object infix
 * @returns postfix
 *******************************/
string convert(const string& infix)
{
	string postfix;
	mystack x;

	size_t index = 0;

	while (index < infix.length())
	{
		// If the current index is lowercase
		if (islower(infix[index]))
		{
			postfix += (infix[index]);
			postfix += " ";
			index++;
		}
		// If the current index is digit
		else if (isdigit(infix[index]))
		{
			while (isdigit(infix[index]))
			{
				postfix += (infix[index]);
				index++;
			}

			postfix += " ";
		}
		// If the current character is a space
		else if (isspace(infix[index]))
		{
			index++;
		}
		// If the current character is left parenthesis
		else if (infix[index] == '(')
		{
			x.push(infix[index]);
			index++;
		}
		// If the current character is right parnthesis
		else if (infix[index] == ')')
		{
			while ((!x.empty()) && (x.top() != '('))
			{
				postfix += x.top();
				postfix += " ";
				x.pop();
			}

			if (x.size() > 0)
			{
				x.pop();
			}
			index++;
		}
		// Operator case
		else
		{
			while ((!x.empty()) && precedence(infix[index]) <= precedence(x.top()))
			{
				postfix += x.top();
				postfix += " ";
				x.pop();
			}
			x.push(infix[index]);
			index++;
		}
	}


	while (!x.empty())
	{
		postfix += x.top();
		postfix += " ";
		x.pop();
	}

	// removes last space
	postfix.pop_back();
	return postfix;
}

/* Switch statement to sort precedence of c++ operators
 *
 * @param char character 'op'
 * @returns the int value of that char in 
 * corrilation to precedence
 ****************************/
int precedence(char op)
{
	switch (op)
	{
	case '~':
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return -1;
	}
}
