//****************************
//
//  insertion_sort.cpp
//  CSCI 241 Assignment 1
//
//  Created by Ryan Park
//
//****************************

#include <iostream>

using namespace std;

int main()
{

 int numbers[1000];
 int count = 0;
 int i,j,temp;

 // input
 while(cin >> numbers[count])
  {
    count++;
  }

 // sorting

  i = 1;
  while (i < count)
   {
	temp = numbers[i];
	j = i;
	while (j > 0 && numbers[j - 1] > temp)
	   {
		numbers[j] = numbers[j - 1];
		j = j - 1;
	   }
	numbers[j] = temp;
	i = i + 1;
   }
 // output
 for (i = 0; i < count; i++)
    cout << numbers[i] << endl;

   return 0;
}
