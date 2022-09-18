#ifndef RECTANGLE_H
#define RECTANGLE_H

//*****************************
//
// rectangle.h
// CSCI 241 Assignment 12
//
// by Ryan Park z1940877
//
//*****************************

#include "shape.h"

class rectangle : public shape
{
private:
	int height;
	int width;

public:
	rectangle(const string&, int, int);
	void print() const;
	double get_area() const;
};

#endif