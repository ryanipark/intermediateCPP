//*********************************
//
// quick_sort.cpp
// CSCI 241 Assignment 3
//
// Created by Ryan Park
//
//*********************************

#include <iostream>
#include <utility>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::setw;


int partition(int array[], int start, int end)
{
	int pivot_index, pivot_value;
	int scan, mid;

	mid = (start + end) / 2;
	swap(array[start], array[mid]);

	pivot_index = start;
	pivot_value = array[start];

	scan = start + 1;
	while (scan <= end)
	{
		if (array[scan] < pivot_value)
		{
			pivot_index = pivot_index + 1;
			swap(array[pivot_index], array[scan]);
		}
		scan = scan + 1;
	}

	swap(array[start], array[pivot_index]);

	return pivot_index;
}


void quick_sort(int array[], int start, int end)
{
	int pivot_point;
	
	if (start < end)
	{
		pivot_point = partition(array, start, end);
		quick_sort(array, start, pivot_point - 1);
		quick_sort(array, pivot_point + 1, end);
	}
}


int main()
{
	int numbers[1000];
	int n;

	while (cin >> numbers[n])
	{
		n++;
	}
	quick_sort(numbers, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << std::setw(8) << numbers[i];
		if ((i + 1) % 9 == 0)
			cout << endl;
	}
	if(n > 8 || n < 8)
		cout << endl;

	return 0;
}
