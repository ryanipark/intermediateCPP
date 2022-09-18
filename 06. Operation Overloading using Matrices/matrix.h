#ifndef MATRIX_H
#define MATRIX_H

//****************************
// CSCI 241 Assignment 6
// matrix.h
// by Ryan Park z1940877
//
//****************************

#include <iostream>

class matrix
{
	// Friends - Operation overloading
	friend std::ostream& operator<<(std::ostream&, const matrix&); // Output
	friend matrix operator+(const matrix&, const matrix&); // Addition
	friend matrix operator*(int, const matrix&); // cA
	friend matrix operator*(const matrix&, int); // Ac
	friend matrix operator*(const matrix&, const matrix&); // matrix * matrix
	friend bool operator==(const matrix&, const matrix&); // is equal
    friend bool operator!=(const matrix&, const matrix& rhs); // is not equal

private:
	// Data 
	int matrix_array[2][2];

public:
	// Constructor
	matrix();
	// Member functions
	matrix(int array[][2]);
	int determinant() const;

};
#endif
