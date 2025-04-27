/*
* Original File Student Name: Jay Fisher
* Student Fix Solution Submitted by: Zachary White
* File Name: M7Discussionfix.cpp
* Date: 04/27/2025
*/

/* ------------------------------------------------------------------------------------------------------------------------------------
* In this program, I identified and corrected three intentional errors. 
* In the Sorting function, the found variable was incorrectly declared as char instead of bool.
* The if (found = true) check used assignment = instead of comparison ==. This was responsible for the incorrect behavior when sorting. 
* The original while (false) loop for input validation was ineffective, so I fixed it to properly check if cin >> user_input fails and handle invalid input. 
* Finally, I ensured the index_memory variable was correctly initialized before each sorting loop to prevent undefined behavior when no smaller number was found. 
* These corrections allow the program to properly accept 10 integers, validate input, sort the numbers in ascending order, and display them cleanly before and after sorting. 
* This exampel did well to showcase correct data types, validating input properly, and carefully handling comparison versus assignment operations in conditional statements.
* ------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//  Sorting Function for selection sort
void Sorting(int number_list[]) {
    bool found = false; // Fix: Use 'bool' not 'char' for true/false logic
    int a, b, smallest_num, index_memory;
    for (a = 0; a < 9; a++) {
        smallest_num = number_list[a];
        index_memory = a; // Fix: Initialize index_memory to current position
        for (b = a + 1; b < 10; b++) {
            if (number_list[b] < smallest_num) {
                smallest_num = number_list[b];
                index_memory = b;
                found = true;
            }
        }
        if (found == true) { // Fix: Should be '==' for comparison, not '='
            number_list[index_memory] = number_list[a];
            number_list[a] = smallest_num;
            found = false;
        }
    }
}

//  Main program
int main() {
    int i = 0, user_input;
    string num_suffix;
    int numbers[10];

    cout << "\n\n  Welcome to my sorting program.";
    cout << "\n  ------------------------------";
    cout << "\n  Please enter 10 integers for me to sort.";

    do {
        if (i == 0) {
            num_suffix = "st";
        }
        else if (i == 1) {
            num_suffix = "nd";
        }
        else if (i == 2) {
            num_suffix = "rd";
        }
        else {
            num_suffix = "th";
        }
        cout << "\n  Enter " << i + 1 << num_suffix << " number: ";

        // Fix: Correct while loop condition for invalid input handling
        while (!(cin >> user_input)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\n  Enter a valid number: ";
        }
        numbers[i] = user_input;
        i++;
    } while (i < 10);

    cout << "\n\n  Here are the numbers you entered:" << endl;
    for (i = 0; i < 9; i++) {
        cout << numbers[i] << ", ";
    }
    cout << numbers[9];

    cout << "\n\n  Here is the sorted list:" << endl;
    Sorting(numbers);
    for (i = 0; i < 9; i++) {
        cout << numbers[i] << ", ";
    }
    cout << numbers[9];

    cout << "\n\n  Press any key to exit...";
    (void)_getch();
    return 0;
}
