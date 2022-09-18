#ifndef CIRCLE_H
#define CIRCLE_H

//***************************************
//
// circle.h
// CSCI 241 Assignment 12
//
// by Ryan Park z1940877
//
//****************************************

#include "shape.h"

class circle : public shape
{
private:
	int radius;

public:
	circle(const string&, int);
	void print() const;
	double get_area() const;

};


#endif