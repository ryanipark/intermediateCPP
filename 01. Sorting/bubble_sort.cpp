//***********************************'
//
//  bubble_sort.cpp
//  CSCI 241 Assignment 1
//  
//  Created by Ryan Park
//
//***********************************


#include <iostream>
#include <utility>

using namespace std;

int main()
{

 int numbers[1000];
 int count = 0;
 int intCount = 0;
 int i,last_swap;

 // input
 while(cin >> numbers[count])
 {
    count++;
    intCount++;
 }

 // sorting
 do
 {
    last_swap = 0;
    i = 1;
    while(i < count)
    {
       if(numbers[i - 1] > numbers[i])
       {
           swap(numbers[i - 1], numbers[i]);
	   last_swap = i;
       }
       i = i + 1;
    }
    count = last_swap;
 }while(count > 1);

 // output
 for (i = 0; i < intCount; i++)
     cout << numbers[i] << endl;

    return 0;
}
