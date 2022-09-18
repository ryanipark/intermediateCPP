//*****************************
//
// shape.cpp
// CSCI 241 Assignment 12
//
// by Ryan Park z1940877
//
//******************************

#include "shape.h"

/* Constructor
 *
 *@param refrence to const string
 *@return none
 *****************************/
shape::shape(const string& color)
{
	this->color = color;
}

/* Destructor do nothing
 *
 *@param none
 *@return none
 ********************/
shape::~shape()
{

}

/* Prints the color of shape object
 *
 *@param none
 *@return none
 ****************************/
void shape::print() const
{
	cout << color;
}


