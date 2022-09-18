#ifndef BOOK_STORE_H
#define BOOK_STORE_H

//*****************************
//
// CSCI 241 Assignment 5
// book_store.h
// By Ryan Park z1940877
//
//*****************************

#include <string>
#include <cstring>

#include "book.h"

class book_store
{
private:
	// declare array of 30 books, and num of books(count)
	book book_array[30];
    int num_books = 0;
	
	// utility function to sort
	void sort_book_data();
	// binary search
	int search_for_isbn(const char*) const;

public:
	// constructor
	book_store() = default;
	// public functions
	void read_book_data(const std::string&);
	void process_orders(const std::string&);
	void print() const;
};

#endif
