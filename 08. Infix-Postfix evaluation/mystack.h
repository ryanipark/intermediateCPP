#ifndef MYSTACK_H
#define MUSTACK_H

//*************************
// mystack.h
//
// CSCI 241 Assignment 8
// by Ryan Park z1940877
//*************************

// Node decleration used within mystack class
struct node
{
	int value;
	node* next;

	node(int value, node* next = nullptr)
	{
		this->value = value;
		this->next = next;
	}
};

class mystack
{

private:

	// 
	node* stk_top = nullptr;
	size_t stk_size = 0;

	// Utility function
	void clone(const mystack&);

public:

	// Defualt constructor
	mystack() = default;
	mystack(const mystack&);
	// Operation overload
	mystack& operator=(const mystack&);
	// Destructor
	~mystack();

	// member functions
	size_t size() const;
	bool empty() const;
	void clear();
	int top() const;
	void push(int);
	void pop();

};

#endif