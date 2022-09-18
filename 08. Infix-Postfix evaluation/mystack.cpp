//************************
// 
// mystack.cpp
//
// CSCI 241 Assignment 8
// by Ryan Park z1940877
//
//************************

#include <iostream>
#include "mystack.h"
using namespace std;

/* Copy constructor
 *  
 *@param of const mystack refrence 
 *@returns none
 ****************************/

mystack::mystack(const mystack& x)
{
	stk_top = nullptr;

	stk_size = x.stk_size;
	
	clone(x);
}

/* Destructor calls clear to clear stack
 * 
 *@param none
 *@returns none
 ****************************/
mystack::~mystack()
{
	clear();
}

/* Copy assignment constructor
 * 
 *@param refrence to constant my stack object
 *@returns refrence to mystack object
 ****************************/
mystack& mystack::operator=(const mystack& x)
{
	if (this != &x)
	{
		clear();

		stk_size = x.stk_size;

		clone(x);
	}
	return *this;
}

/* Gets the stack size
 * 
 *@param None
 *@returns size_t size of stack
 ****************************/
size_t mystack::size() const
{
	return stk_size;
}

/* Checks if stack is empty or not
 * 
 *@param none
 *@returns bool true/false
 ****************************/
bool mystack::empty() const
{
	if (stk_size == 0)
		return true;
	else
		return false;
}

/* Clears the stack
 * 
 *@param none
 *@returns none
 ****************************/
void mystack::clear()
{
	while (!empty())
	{
		pop();
	}
}

/* Retrieves top item from stack
 * 
 *@param none
 *@returns int of stk top pointer to the value
 ****************************/
int mystack::top() const
{
	return stk_top->value;
}

/* Pushes item onto the stack
 * 
 *@param integer value to be pushed
 *@returns nothing
 ****************************/
void mystack::push(int value)
{
	node* new_node = new node(value, stk_top);
	stk_top = new_node;
	stk_size++;
}

/* Removes top item from stack
 * 
 *@param none
 *@returns none
 ****************************/
void mystack::pop()
{
	node* delete_node = stk_top;
	stk_top = stk_top->next;
	delete delete_node;
	stk_size--;
}

/* Duplicates two stack items
 *   Basically a utility function
 * 
 *@param refrence to const mystack x
 *@returns nothing
 ****************************/
void mystack::clone(const mystack& x)
{
	node* last = nullptr;
	node* ptr = x.stk_top;

	while (ptr != nullptr)
	{
		node* new_node = new node(ptr->value);

		if (last == nullptr)
		{
			stk_top = new_node;
		}
		else
		{
			last->next = new_node;
		}

		last = new_node;
		ptr = ptr->next;
	}
}
