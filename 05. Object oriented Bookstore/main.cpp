//***************************
//
// CSCI 241 Assignment 5
// main.cpp
// by Ryan Park z1940877
//
//***************************

#include <iostream>

// header calls
#include "book.h"
#include "book_store.h"

using namespace std;

int main()
{
	// create book_store object
	book_store bs;
	// call book_store member functions using files specified
	//   then goes through and prints after running through member
	//	   member functions.
	bs.read_book_data("bookdata");
	bs.print();
	bs.process_orders("orders.txt");
	bs.print();


	return 0;
}
