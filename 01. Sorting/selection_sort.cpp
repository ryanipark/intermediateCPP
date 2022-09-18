//***************************
//
//  selection_sort.cpp
//  CSCI 241 Assignment 1
//
//  Created by Ryan Park
//
//**************************

#include <iostream>

using namespace std;

int main()
{

 int numbers[1000];
 int count = 0;
 int i,j,temp,min_index;

 // input
 while(cin >> numbers[count])
 {
    count++;
 }

 // sorting
 for (i = 0; i < count - 1; i++)
 {
    min_index = i;
    for(j = i + 1; j < count; j++)
    {
       if(numbers[j] < numbers[min_index])
	    min_index = j;
    }
	// switch the lower number each pass
	temp = numbers[i];
	numbers[i] = numbers[min_index];
	numbers[min_index] = temp; 
 }

 // output
 for (i = 0; i < count; i++)
    cout << numbers[i] << endl;

   return 0;
}
