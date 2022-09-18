//****************************
// mystack.cpp
//
// CSCI 241 Assignment 7
// by Ryan Park z1940877
//
//****************************
#include "mystack.h"

using namespace std;


/*
 * Default constructor setting
 *  the private data members
 * 
 * @param none
 * @return none
 *******************************/
mystack::mystack()
{
	stack_array_pointer = nullptr;
	stack_capacity = 0;
	stack_size = 0;
}

/*
 * Copy constructor, it initializes
 *  a new mystack object and sets the
 *  values the same as each other
 *
 * @param const refrence to mystack 
 * @return returns nothing
 *******************************/
mystack::mystack(const mystack& x)
{
	stack_size = x.stack_size;
	stack_capacity = x.stack_capacity;

	if (x.stack_capacity > 0)
	{
		stack_array_pointer = new char[stack_capacity];

	}
	else
	{
		stack_array_pointer = nullptr;
	}

	for (size_t i = 0; i < stack_size; i++)
	{
		stack_array_pointer[i] = x.stack_array_pointer[i];
	}
}

/*
 * Destructor, deletes the stack array
 *
 * @param none
 * @return none
 *******************************/
mystack::~mystack()
{
	delete stack_array_pointer;
}

/*
 * Operation =, checks if left hand side is equal to x
 *
 * @param refrence to constant mystack x
 * @return refrence to mystack object
 *******************************/
mystack& mystack::operator=(const mystack& x)
{
	if (this != &x)
	{
		delete[] stack_array_pointer;

		stack_size = x.stack_size;
		stack_capacity = x.stack_capacity;
		stack_array_pointer = new char[stack_capacity];

		for (size_t i = 0; i < stack_size; i++)
		{
			stack_array_pointer[i] = x.stack_array_pointer[i];
		}
	}

	return *this;
}

/*
 * Displays the current stack_capacity
 *
 * @param none
 * @return size_t value of stack_capacity
 *******************************/
size_t mystack::capacity() const
{
	return stack_capacity;
}

/*
 * Displays the current stack_size
 *
 * @param none
 * @return size_t value of stack_size
 *******************************/
size_t mystack::size() const
{
	return stack_size;
}

/*
 * Checks if stack_size is empty(0)
 *  or not
 *
 * @param none
 * @return boolean true/false
 *******************************/
bool mystack::empty() const
{
	if (stack_size == 0)
		return true;
	else
		return false;
}

/*
 * Clears the stack size.
 *
 * @param none
 * @return none
 *******************************/
void mystack::clear()
{
	stack_size = 0;
}

/*
 * Reserves capacity space in the 
 *  object, does not modify stack size
 *  OR contents of the array
 *
 * @param size_t value of requested change
 * @return none
 *******************************/
void mystack::reserve(size_t n)
{
	if (n < stack_size || n == stack_capacity)
	{
		return;
	}

	char* temp;
	temp = new char[n];

	for (size_t i = 0; i < stack_size; i++)
	{
		temp[i] = stack_array_pointer[i];
	}

	stack_capacity = n;

	delete[] stack_array_pointer;

	stack_array_pointer = temp;
}

/*
 * Displays the value of the item
 *  on the top of the stack
 *
 * @param none
 * @return const char refrence 
 *******************************/
const char& mystack::top() const
{
	return stack_array_pointer[stack_size - 1];
}

/*
 * Pushes/places the char value passed
 *  onto the top of the stack
 *
 * @param char value
 * @return none
 *******************************/
void mystack::push(char value)
{
	if (stack_size == stack_capacity)
	{
		if (stack_capacity == 0)
		{
			reserve(1);
		}
		else
		{
			reserve(stack_capacity * 2);
		}
	}

	stack_array_pointer[stack_size] = value;
	stack_size += 1;
}

/* 
 * Takes the item/value off the top of the stack
 *
 * @param none
 * @return none
 *******************************/
void mystack::pop()
{
	stack_size = stack_size - 1;
}
