//***********************************
//
// assign12.cpp
// CSCI 241 Assignment 12
//
// by Ryan Park z1940877
//
//***********************************

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "shape.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

using namespace std;

int main()
{

	/* Create a vector of pointer to shapes
     * Load in the shapes from assignment sheet
	 * Print them all
	 * Safe cast to check if circle
	 * Print only circles
	 * Delete allocated space from vector
	 */
	
	vector<shape*> shapes;

	shapes.push_back(new circle("green", 10));
	shapes.push_back(new rectangle("red", 8, 6));
	shapes.push_back(new triangle("yellow", 8, 4));
	shapes.push_back(new triangle("black", 4, 10));
	shapes.push_back(new circle("orange", 5));
	shapes.push_back(new rectangle("blue", 3, 7));

	cout << "Printing all shapes...\n\n";

	for (size_t i = 0; i < shapes.size(); i++)
	{
		shapes[i]->print();
	}

	cout << "\nPrinting only circles...\n\n";


	for (size_t i = 0; i < shapes.size(); i++)
	{
		circle* p = dynamic_cast<circle*>(shapes[i]);

		if (p != nullptr)
		{
			p->print();
		}

	}


	for (size_t i = 0; i < shapes.size(); i++)
	{
		delete shapes[i];
	}


	return 0;
}