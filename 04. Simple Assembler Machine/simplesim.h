#ifndef SIMPLESIM_H
#define SIMPLESIM_H

// header lock

//**************************************
//
//  simplesim.h
//  CSCI 241 Assignment 4
//
// Created by Ryan Park z1940877
//
//***************************************

class simplesim
{
private:
	//memory
	int memory[100];

	//registers
	int accumulator = 0;
	int instruction_counter = 0;
	int instruction_register = 0;
	int operation_code = 0;
	int operand = 0;

	// utility function
	bool invalid_word(int) const;

public:

	simplesim();
	bool load_program();
	void execute_program();
	void dump() const;
};

#endif