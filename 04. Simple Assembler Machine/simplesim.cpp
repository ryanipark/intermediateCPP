
//**********************
//
// simplesim.cpp
// Assignment 4 CSCI 241
//
// Created by Ryan Park
//
//**********************

#include <iostream>
#include <iomanip>

#include "sml.h"
#include "simplesim.h"

using namespace std;


simplesim::simplesim() // initializze the memory array to 7777
{

    for (int i = 0; i < 100; i++)
        memory[i] = 7777;
}

bool simplesim::load_program()
{
    int count = 0;
    int instruction; // word being read

    while (cin >> instruction && instruction != -99999)
    {
        if (invalid_word(instruction))
        {
            cout << "*** ABEND: pgm load: invalid word ***\n";
            return false;
        }

        if (count >= 100)
        {
            cout << "*** ABEND: pgm load: pgm too large ***\n";
            return false;
        }


        // copy instruction into memory and increment count
        memory[count] = instruction;
        count++;
    }

    return true;
}



// execute loades imsplesim
void simplesim::execute_program()
{

    bool done = false;

    while (!done)
    {
        // instruction fetch
        // test intrusction_counter, if >=100, addressability
        if (instruction_counter >= 100)
        {
            cout << "*** ABEND: addressablility error\n";
            return;
        }

        instruction_register = memory[instruction_counter];

        operation_code = instruction_register / 100; // first two takenof intrusction
        operand = instruction_register % 100; // takes the last two digits of the intrusction

        // instruction execute - goes through by word and executes upon the switch statement
        switch (operation_code)
        {
        case READ:
            int word;
            cin >> word;
            if (word >= -9999 && word <= 9999)
            {
                memory[operand] = word;
                cout << "READ: " << showpos << internal << setfill('0') 
                    << setw(5) << word << endl;
            }
            else
            {
                cout << "** ABEND: illegal input ***\n";
                return;
            }
            break;

        case WRITE:
            cout << showpos << internal << setfill('0') << setw(5) 
                << memory[operand] << endl;
            break;

        case LOAD:
            accumulator = memory[operand];
            break;

        case STORE:
            memory[operand] = accumulator;
            break;

        case ADD:
            if ((accumulator + memory[operand]) < -9999) // check for underflow
            {
                cout << "*** ABEND: underflow ***\n";
                return;
            }
            else if ((accumulator + memory[operand]) > 9999) // check for overflow
            {
                cout << "*** ABEND: overflow ***\n";
                return;
            }
            else
                accumulator = accumulator + memory[operand];
            break;

        case SUBTRACT:
            if ((accumulator - memory[operand]) < -9999) // check for underflow
            {
                cout << "*** ABEND: underflow ***\n";
                return;
            }
            else if ((accumulator - memory[operand]) > 9999) // check for overflow
            {
                cout << "*** ABEND: overflow ***\n";
                return;
            }
            else
                accumulator = accumulator - memory[operand];
            break;

        case MULTIPLY:
            if ((accumulator * memory[operand]) < -9999)
            {
                cout << "*** ABEND: underflow ***\n";
                return;
            }
            else if ((accumulator * memory[operand]) > 9999)
            {
                cout << "*** ABEND: overflow ***\n";
                return;
            }
            else
                accumulator = accumulator * memory[operand];
            break;

        case DIVIDE:
            if (memory[operand] == 0)
            {
                cout << "*** ABEND: attempted division by 0 ***\n";
                return;
            }
            accumulator = accumulator / memory[operand];
            break;

        case BRANCH:
            instruction_counter = memory[operand];
            break;

        case BRANCHZERO:
            if (accumulator == 0)
                instruction_counter = memory[operand];
            else
                instruction_counter++;
            break;

        case BRANCHNEG:
            if (accumulator < 0)
                instruction_counter = memory[operand];
            else
                instruction_counter++;
            break;

        case HALT:
            cout << "*** Simplesim execution terminated ***\n";
            done = true;
            break;

        default:
            cout << "*** ABEND: invalid operation code ***\n";
            return;

        }

        if ((operation_code < BRANCH || operation_code > BRANCHNEG) && !done)
            instruction_counter++;
    }
}


// dumps simplesim memory & registers

void simplesim::dump() const
{

    // Print registers
    cout << "\nREGISTERS: \n";
    cout << left << setfill(' ') << setw(24) << "accumulator:"; // formatted middle output on all, left assigned identifier
    cout << internal << setfill('0') << showpos << setw(5) << accumulator << endl;
    cout << left << setfill(' ') << setw(24) << "instruction_counter:";
    cout << right << setfill('0') << noshowpos << setw(2) << instruction_counter << endl;
    cout << left << setfill(' ') << setw(24) << "instruction_register:";
    cout << internal << setfill('0') << showpos << setw(5) << instruction_register << endl;
    cout << left << setfill(' ') << setw(24) << "operation_code:";
    cout << right << setfill('0') << noshowpos << setw(2) << operation_code << endl;
    cout << left << setfill(' ') << setw(24) << "operand:";
    cout << right << setfill('0') << noshowpos << setw(2) << operand << endl;

    // printing memory
    cout << std::left << "\nMEMORY:" << endl;
    
    cout << "       "; // formatting for header blank space
    for (int i = 0; i < 10; i++) // prints header of memory from 0-9
    {
        cout << std::setw(6) << setfill(' ') << i; // formatted header loop
    }

    int mem = 0;
    cout << "\n" << setw(2) << right << noshowpos << mem << " "; // initial collum format
    mem = 10;

    for (int i = 0; i < 100; i++)
    {
        cout << std::setw(5) << std::internal << std::showpos << setfill('0') << memory[i];
        cout << " ";// change formating in the future
        if ((i + 1) % 10 == 0) // every 10 lines it will
        {
            if (mem < 100) // insures it does not go over 90
            {
                cout << endl; // create a new line
                cout << std::right << std::noshowpos << setfill('0') << setw(2) << mem;
                cout << " ";  // print memory on collum with correct formating
                mem = mem + 10; // incriment by 10 for next time it reaches 10 in the loop
            }
            else // when max is reached it resets the command line back to the bottom
                cout << endl;
        }
    }



}


bool simplesim::invalid_word(int word) const
{
    if (word < -9999 || word > 9999)
        return true;
    else
        return false;
}
