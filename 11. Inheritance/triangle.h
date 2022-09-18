#ifndef TRIANGLE_H
#define TRIANGLE_H

//*********************************
//
// triangle.h
// CSCI 241 Assignment 12
//
// by Ryan Park z1940877
//
//*********************************

#include "shape.h"

class triangle : public shape
{
private:
	int height;
	int base;

public:
	triangle(const string&, int, int);
	void print() const;
	double get_area() const;

};

#endif