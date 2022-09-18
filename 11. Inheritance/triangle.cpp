//*********************************
//
// triangle.cpp
// CSCI 241 Assignment 12
//
// by Ryan Park z1940877
//
//*********************************

#include <iostream>
#include <iomanip>
#include <string>
#include "triangle.h"
using namespace std;

/* Constructor
 *
 *@param string for color of triangle
 *@param int for height of triangle
 *@param int for base of triangle
 * 
 *@return color to shape constructor
 *************************************/
triangle::triangle(const string& color, int height, int base) :
	shape(color)
{
	this->height = height;
	this->base = base;
}


/* Prints the triangles contents along
 *	with shape color
 *
 *@param none
 *@return none
 ********************************/
void triangle::print() const
{
	shape::print();
	//cout << setprecision(0);
	cout << " triangle, height " << height << ", base " << base << ", area "
		<< get_area() << endl;

}

/* Gets the area of the triangle
 *
 *@param none
 *@return double of area
 **************************/
double triangle::get_area() const
{
	double area = (base * height) * 0.5;
	return area;
}


