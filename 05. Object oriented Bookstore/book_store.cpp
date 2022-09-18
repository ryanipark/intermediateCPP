//******************************
// CSCI 241 Assignment 5
// book_store.cpp
// By Ryan Park z1940877
//
//******************************

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>

#include "book_store.h"

using namespace std;


/**
 * Reads in book data from file specified in main.cpp
 * @file_name is file specified
 * Then sorts the data using member function
 *  
 * @returns nothing, just uses for input into book_array
 * 
 ************************************************************/

void book_store::read_book_data(const string& file_name) // read in initial data
{
    ifstream in_file;

    in_file.open(file_name);
    if (!in_file)
    {
        cerr << "Unable to open file." << file_name << endl;
        exit(1);
    }

    in_file.read((char*)this, sizeof(book_store));

    in_file.close();

    sort_book_data();
}

/**
 *
 *  Sorts the data from input using selection sort
 * 
 * @return nothing, as it just modifies the order of the book_array
 * 
 *******************************************************************/

void book_store::sort_book_data() // function to sort using selection sort
{
    int i, j, min_index;
    book temp;

    for (i = 0; i < num_books - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < num_books; j++)
        {
            if (strcmp(book_array[j].get_isbn(), book_array[min_index].get_isbn()) < 0)
                min_index = j;
        }
        // switch the lower number each pass
        temp = book_array[i];
        book_array[i] = book_array[min_index];
        book_array[min_index] = temp;
    }
}

/**
 * Takes file name in from main.cpp
 * Then while it reads it trys to find a match in isbn
 * If it finds match in ISBN from the book data stored
 * It will process and fulfill the order specified by ISBN
 *  * 
 * @file_name is what is specified
 * 
 * @returns nothing as it, but prints orders processed
 * 
 * *******************************************************/

void book_store::process_orders(const string& file_name)
{
    string order_number;
    char order_isbn[11];
    int order_quantity;

    ifstream in_file;

    // input validation
    in_file.open(file_name);
    if (!in_file)
    {
        cerr << "Unable to open file." << file_name << endl;
        exit(1);
    }

    cout << left << "\nOrder listing\n\n";

    // if valid, process and sort input
    in_file >> order_number; 
    while (in_file)
    {
        in_file >> order_isbn;
        in_file >> order_quantity;

        int index = search_for_isbn(order_isbn);
        if (index == -1)
        {
            // Search failed, print error message.
            cout << left << "Order #" << order_number << ": error - " << "ISBN " << order_isbn << " does not exist\n";
        }
        else
        {
            // Search succeeded. Fulfill the order for
            // the book located at book_array[index] and
            // print the results.
            int num_shipped = book_array[index].fulfill_order(order_quantity);
            cout << left << "Order #" << order_number << ": ISBN " << order_isbn << ", " << num_shipped;
            cout << left << " of " << order_quantity << " shipped, " << "order total $";
            cout << left << fixed << setprecision(2) << (book_array[index].get_price() * num_shipped);
            cout << endl;
        }

        in_file >> order_number;
    }

    in_file.close();
}


/**
 * takes in isbn, searches book_store and compares isbn to find if
 * the book exists
 * 
 * @const char* isbn, does not modify only uses to search
 * 
 * @returns book_array[mid] which is a match of ISBN
 * 
 * *******************************************/

int book_store::search_for_isbn(const char* isbn) const // SEARCH FOR ISBN IN DATABASE
{
    int low = 0;
    int high = num_books - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (strcmp(isbn, book_array[mid].get_isbn()) == 0)
        {
            // if success return to processing else statement
            return mid;
        }
        if (strcmp(isbn, book_array[mid].get_isbn()) < 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1; // failed search
}

/**
 * prints the listings of book book_store
 * 
 * @returns nothing
 * 
 * *************************************/
void book_store::print() const
{
    // format title and header
    cout << "\nBook Inventory listing\n"; 
    cout << endl;
    cout << left << setw(14) << "ISBN";
    cout << left << setw(44) << "Title";
    cout << right << setw(5) << "Price";
    cout << right << setw(7) << "Qty.";
    cout << endl << endl;

    // print book listings
    for (int i = 0; i < num_books; i++)
    {
        book_array[i].print();
        cout << endl;
    }
}
