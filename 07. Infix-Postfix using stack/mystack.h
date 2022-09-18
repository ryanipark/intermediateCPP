#ifndef MYSTACK_H
#define MYSTACK_H

//*********************************
//
// mystack.h
//
// CSCI 241 Assignment 7
// by Ryan Park z1940877
//
//*********************************

#include <cstdlib>

class mystack 
{

private:
	// data members
	char* stack_array_pointer;
	size_t stack_capacity;
	size_t stack_size;

public:

	mystack(); // default contructor
	mystack(const mystack& x); // copy constructor
	~mystack(); // destructor
	mystack& operator=(const mystack&); // overloaded operator
	size_t capacity() const; // returns capacity
	size_t size() const; // returns size
	bool empty() const; // checks if stack is empty
	void clear(); // sets tack size to 0
	void reserve(size_t n); // modifies stack capacity
	const char& top() const; // returns the item at the top of the stack
	void push(char value); // "pushes" value character passed to top of stack
	void pop(); // pops item off the top


};

#endif