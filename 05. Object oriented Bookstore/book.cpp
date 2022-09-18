//*****************************
//
// CSCI 241 Assignment 5
// book.cpp
// By Ryan Park z1940877
//
//*****************************

#include <iostream>
#include <iomanip>

#include "book.h"

using namespace std;

/**
 * Default constructor.
 */
book::book()
{
	price = 0;
	stock = 0;
}

/**
 * Accessor for ISBN.
 *
 * @return The ISBN.
 */
const char* book::get_isbn() const
{
	return isbn;
}

double book::get_price() const
{
	return price;
}

/**
 * Given an order request, calculates the number of books to ship.
 *
 * @param request The number of books ordered.
 *
 * @return The number of books shipped.
 */
int book::fulfill_order(int request)
{
    // if request is below 0 return 0 , invalid | keeps stock the same
	if (request <= 0)
	{
		request = 0;
		return 0;
	}
	if (request <= stock) // if request is less then or equal to stock set stock
	{
		stock = stock - request;
	}
	else if (request > stock) // if request is greater then, request is what stock is, then stock is left over
	{
		request = stock;
		stock = 0;
	}

	return request; // returns request for the two if statements that are valid
}

/**
 * Called upon for book to print its contents accordingly
 * 
 * @returns nothing and is constant
 *
 **************************************************/
void book::print() const
{
	cout << left << setw(14) << isbn;
	cout << left << setw(44) << title;
	cout << right << setw(5) << fixed << setprecision(2) << price;
	cout << right << setw(6) << stock;
}
