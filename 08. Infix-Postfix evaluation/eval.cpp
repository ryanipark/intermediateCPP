//**************************
//
// eval.cpp
//
// CSCI 241 Assignment 8
// by Ryan Park z1940877
//
//**************************


#include <iostream>
#include <sstream>
#include <string>

#include "eval.h"
#include "mystack.h"
#include "inpost.h"


using namespace std;


/* Evalutes the post fix string
 * used post fix string to commit operations
 * on values within the string, storing them in the stack
 * then removing them or changing them as need be
 * 
 *@param refrence to constant string object postfix
 *@returns integer , the last item in the stack (top)
 ****************************/
int evaluate(const string& postfix)
{
	string op;
	stringstream ss(postfix);

	// Declare eval_stack
	mystack eval_stack;
	
	while(ss >> op)
	{
		// op is a c++ string containing the next operator/operand
		// in the postfix expression
		

		// if token is integer, push it on the eval stack
		if (isdigit(op[0]))
		{
			int x = stoi(op);
			eval_stack.push(x);

		}
		// if token is a variable, calculate the new value of the variable 
		if (isalpha(op[0]))
		{
			char var = op[0];
			int x = var - 'a';
			eval_stack.push(x);
		}


		// if the token is a ~ operator, get the top item from the eval_stack, pop the stack, apply the operator 
		// and push the result on the eval stack
		else
		{

			if (op[0] == '~')
			{
				// Pop the top item from the stack
				int last = eval_stack.top();
				// Pop that item off the stack
				eval_stack.pop();
				// Do the operation (~ = -1)
				int x = (last * -1);
				// Push the result(y) back onto the stack
				eval_stack.push(x);

			}

			if (op[0] == '+')
			{
				// Get right opperand
				int right = eval_stack.top();
				// Pop the value off
				eval_stack.pop();
				// Get left operand
				int left = eval_stack.top();
				// Pop that value off too
				eval_stack.pop();

				// Perform calculation
				int result = (left + right);
				// Push that value back onto the stack
				eval_stack.push(result);
			}

			if (op[0] == '-')
			{
				// Get right opperand
				int right = eval_stack.top();
				// Pop the value off
				eval_stack.pop();
				// Get left operand
				int left = eval_stack.top();
				// Pop that value off too
				eval_stack.pop();

				// Perform calculation
				int result = (left - right);
				// Push that value back onto the stack
				eval_stack.push(result);
			}

			if (op[0] == '*')
			{
				// Get right operand
				int right = eval_stack.top();
				// Pop the value off the stack
				eval_stack.pop();
				// Get left operand
				int left = eval_stack.top();
				// Pop that value off too
				eval_stack.pop();
				
				// Perform calculation
				int result = (left * right);
				// Push that value back onto the stack
				eval_stack.push(result);
			}

			if (op[0] == '/')
			{
				// Get right operand
				int right = eval_stack.top();
				// Pop the value off the stack
				eval_stack.pop();
				// Get left operand
				int left = eval_stack.top();
				// Pop that item off as well
				eval_stack.pop();
				
				// 
				 
				// Test if divison is by 0
				if (right == 0)
				{
					cout << "*** Division by 0 ***\n";
					eval_stack.push(0);
				}
				// If not peform calculation and push result
				else
				{
					int result = (left / right);
					eval_stack.push(result);
				}
			}

			if (op[0] == '^')
			{
				// Get right operand
				int right = eval_stack.top();
				// Pop that value off the stack
				eval_stack.pop();
				// Get left operand
				int left = eval_stack.top();
				// Pop that off too
				eval_stack.pop();

				// If it wants the power of 1 push value back
				if (right == 0)
				{
					eval_stack.push(1);
				}

				// If it wants the power <1 Do the math
				else
				{
					int result = left;

					for (int i = 1; i < right; i++)
					{
						result = result * left;
					}
					// Push the result back to stack
					eval_stack.push(result);
				}



			}
		}
	}
	return eval_stack.top();
}