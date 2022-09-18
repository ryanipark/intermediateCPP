//********************************
//
//  hanoi.cpp
//  CSCI 241 Assignment 2
//
//  Created by Ryan Park z1940877
//
//********************************


#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

using std::cout;
using std::endl;
using std::stoi;

int hanoi(int n, int peg1, int peg2, int peg3)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        hanoi(n - 1, peg1, peg3, peg2);
        cout << n << " " <<  peg1 << "->" << peg2 << endl;
        hanoi(n - 1, peg3, peg2, peg1);
    }
    return 1;
}

int main(int argc, char* argv[])
{
    int n;
    n = stoi(argv[1]);

    if(n > 0 && n <= 5) // input validation
        hanoi(n, 1, 2, 3);
    else
        cout << "Invalid entry." << endl;

    return 0;
}
