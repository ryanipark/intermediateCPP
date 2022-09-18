//********************************
// CSCI 241 Assignment 6
// matrix.cpp
// by Ryan Park z1940877
//
//********************************

#include <iostream>
#include "matrix.h"

#define ROW_SIZE 2
#define COL_SIZE 2

using namespace std;

/**
 *  Identity matrix constructor
 *  Sets matrix array to default [[1, 0], [0, 1]] 
 * 
 * @param none
 * @returns none
******************************************/
matrix::matrix()
{
	matrix_array[0][0] = 1;
	matrix_array[0][1] = 0;
	matrix_array[1][0] = 0;
	matrix_array[1][1] = 1;
}

/**
 *  Takes in int array and assigns to objects matrix_array
 * 
 * @param takes in an int array
 * @returns nothing
******************************************/
matrix::matrix(int array[][2])
{
	int i, j;

	for (i = 0; i < ROW_SIZE; i++)
	{
		for (j = 0; j < COL_SIZE; j++)
		{
			matrix_array[i][j] = array[i][j];
		}
	}
}

/**
 * overload of << allowing for os to directly output objects matrix_array
 *
 *@param ostream refrence os, and const matrix refrence object
 *@returns the os with proper formatting and output of the matrix_array
******************************************/
ostream& operator<<(ostream& os, const matrix& m)
{
	os << "[[" << m.matrix_array[0][0] << ", " << m.matrix_array[0][1] << "], [" << m.matrix_array[1][0]
		<< ", " << m.matrix_array[1][1] << "]]";

	return os;
}

/**
 * determines the determinate of an objects matrix_array
 *
 * @param none
 * 
 *@returns the determinant as int
******************************************/
int matrix::determinant() const
{
	int deter;
	deter = ((matrix_array[0][0] * matrix_array[1][1]) - (matrix_array[0][1] * matrix_array[1][0]));
	return deter;
}

/**
 * Adds two matrices together 
 * 
 * @param takes refrence to a matrix object for both lhs/rhs
 * @returns the new matrix object result
******************************************/
matrix operator+(const matrix& lhs, const matrix& rhs)
{
	matrix result;

    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COL_SIZE; j++)
        {
            result.matrix_array[i][j] = lhs.matrix_array[i][j] + rhs.matrix_array[i][j];
        }
    }

	return result;
}

/**
 *   Multiplies object by rhs int
 * 
 *		 Ac
 *  
 * @param takes in refrence to const matrix and int as rhs
 *
 * @returns the results matrix after right operand scalar 
 *  multiplication
 *
******************************************/
matrix operator*(const matrix& lhs, int rhs)
{
	// initilize as left opperand
	matrix temp = lhs;

	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)
		{
			temp.matrix_array[i][j] = temp.matrix_array[i][j] * rhs;
		}
	}
	return temp;
}

/**
 *  takes two refrnece calls to matrix object, uses lhs and rhs to multiply results into
 *	results (temp) object's matrix_array
 *		matrix * matrix
 *
 * @param right operand and assigns temp to left
 *
 * @returns the results of lhs * rhs
 *
******************************************/
matrix operator*(const matrix& lhs, const matrix& rhs)
{
	matrix temp;

	// multiplication following the matrix * matrix logic
	// for each spot in the result(temp) object array

	temp.matrix_array[0][0] = ((lhs.matrix_array[0][0] * rhs.matrix_array[0][0]) 
							+ (lhs.matrix_array[0][1] * rhs.matrix_array[1][0]));
	temp.matrix_array[0][1] = ((lhs.matrix_array[0][0] * rhs.matrix_array[0][1])
							+ (lhs.matrix_array[0][1] * rhs.matrix_array[1][1]));
	temp.matrix_array[1][0] = ((lhs.matrix_array[1][0] * rhs.matrix_array[0][0])
							+ (lhs.matrix_array[1][1] * rhs.matrix_array[1][0]));
	temp.matrix_array[1][1] = ((lhs.matrix_array[1][0] * rhs.matrix_array[0][1])
							+ (lhs.matrix_array[1][1] * rhs.matrix_array[1][1]));

    return temp;
}

/**
 *  Multiplies left hand int by rhs object 
 * 
 *		cA 
 * 
 * @param int lhs and refrnece to matrix object as rhs
 * 
 * @returns the results matrix after left operand scalar
 *  multiplication
 *
******************************************/
matrix operator*(int lhs, const matrix& rhs)
{
	//initilize as right opperand
	matrix temp;

	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)
		{
			temp.matrix_array[i][j] = rhs.matrix_array[i][j] * lhs;
		}
	}
    
	return temp;
}

/**
 *   This member function takes one paramter refrence to matrix on right operand
 *   Then compares to left operand, checks if they ARE the same
 *
 * @param rhs refrence to matrix object
 *
 * @returns boolean true or false depending on case
 *
******************************************/
bool operator==(const matrix& lhs, const matrix& rhs)
{
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)
		{
			if (lhs.matrix_array[i][j] != rhs.matrix_array[i][j])
			{
				return false;
			}
		}
	}
	return true;
}


/**
 *   This member function takes one paramter refrence to matrix on right operand
 *   Then compares to left operand, checks if they are NOT the same
 *
 * @param rhs refrence to matrix object
 *
 * @returns boolean true or false depending on case
 *
******************************************/
bool operator!=(const matrix& lhs, const matrix& rhs)
{
	if (lhs == rhs)
        return false;
    else
	    return true;
}


