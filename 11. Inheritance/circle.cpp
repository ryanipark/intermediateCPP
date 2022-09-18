//****************************
//
// circle.cpp
// CSCI 241 Assignment 12
//
// by Ryan Park z1940877
//
//****************************

#include <string>
#include <cmath>
#include <iomanip>
#include "circle.h"
using namespace std;




/* Constructor
 *
 *@param color of the circle
 *@param radius of circle
 *@return color to shape constructor
 ************************/
circle::circle(const string& color, int radius) :
	shape(color)
{
	this->radius = radius;
}


/* Prints the shape contents along
 *    with circle
 *
 *@param none
 *@return none
 *******************************/
void circle::print() const
{
	shape::print();

	cout << " circle, radius " << radius << ", area " << get_area() << endl;
}

/* Returns area of the circle given this->radius
 *
 *@param none
 *@return double area
 **************************/
double circle::get_area() const
{
	cout << setprecision(6);
	double area = (radius * radius) * 3.14159;
	return area;
}