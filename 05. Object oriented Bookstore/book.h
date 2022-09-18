#ifndef BOOK_H
#define BOOK_H

//*****************************
//
// CSCI 241 Assignment 5
// book.h
// By Ryan Park z1940877
//
//*****************************

class book
{
private:
	// declaring what a book is
	char isbn[11]{ "None" };
	char title[41]{ "None" };
	double price;
	int stock;

public:
	// constructor to set price/stock
	book();

	// functions
	const char* get_isbn() const;
	double get_price() const;
	int fulfill_order(int);
	void print() const;
};

#endif
