#ifndef SHAPE_H
#define SHAPE_H

//********************************
//
// shape.h
// CSCI 241 Assignment 12
//
// by Ryan Park z1940877
//
//********************************

#include <iostream>
#include <string>
using namespace std;

class shape
{
private:
	string color;

public:
	shape(const string&);
	virtual ~shape();
	virtual void print() const;
	virtual double get_area() const = 0;

};

#endif