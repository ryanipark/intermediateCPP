//*********************************
//
// merge_sort.cpp
// CSCI 241 Assignment 3
//
// Created by Ryan Park
//
//*********************************

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;


void merge(int array[], int start, int mid, int end)
{
	int temp[end - start + 1];

	int i = start;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= end)
	{
		if (array[i] < array[j])
		{
			temp[k] = array[i];
			i = i + 1;
		}
		else
		{
			temp[k] = array[j];
			j = j + 1;
		}
		k = k + 1;
	}

	while (i <= mid)
	{
		temp[k] = array[i];
		i = i + 1;
		k = k + 1;
	}

	while (j <= end)
	{
		temp[k] = array[j];
		j = j + 1;
		k = k + 1;
	}
	
	// copy elements of temp back into array
	for (k = 0, i = start; i <= end; k++, i++)
	{
		array[i] = temp[k];
	}

}


void merge_sort(int array[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

		merge_sort(array, start, mid);
		merge_sort(array, mid + 1, end);

		merge(array, start, mid, end);
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
	merge_sort(numbers, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << std::setw(8) << numbers[i];
		if ((i + 1) % 8 == 0)
			cout << endl;
	}
	if (n > 8 || n < 8)
		cout << endl;

	return 0;
}
