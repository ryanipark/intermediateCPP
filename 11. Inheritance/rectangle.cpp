//*****************************
//
// rectangle.cpp
// CSCI 241 Assignment 12
//
// by Ryan Park z1940877
//
//*****************************

#include <iostream>
#include <iomanip>
#include "rectangle.h"

using namespace std;


/* Constructor
 *
 *@param string for shape color
 *@param int for height of rectangle
 *@param int for width of rectangle
 * 
 *@return color to shape constructor
 *****************************/
rectangle::rectangle(const string& color, int height, int width) :
						shape(color)
{
	this->height = height;
	this->width = width;
}

/* Prints rectangles contents along
 *   with the shapes color
 *
 *@param none
 *@return none
 *****************************/
void rectangle::print() const
{
	shape::print();
	//cout << setprecision(0);
	cout << " rectangle, height " << height << ", width " << width
		<< ", area " << get_area() << endl;
}

/* Returns double of area
 *
 *@param none
 *@return double area
 *****************************/
double rectangle::get_area() const
{
	double area = width * height;
	return area;
}