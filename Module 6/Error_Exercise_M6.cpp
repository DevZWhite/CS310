/* Source Code:
 * -------------------------------------------------
 * Student Name: Jay Fisher
 * File Name: M6_Discussion.cpp
 * Data: 04/16/2025
 * Visual C++ 2022   00476 - 80000 - 00000 - AA685
 * Microsoft Visual C++ 2022
 * -------------------------------------------------
 */

/*
 * ------------------------------------
 * Fix Submitted by:
 * Student Name: Zachary White
 * File Name: Error_Exercise_M6.cpp
 * Data: 04/16/2025
 * IDE: Microsoft Visual Code
 * ------------------------------------
*/


/*
 * ------------------------------------------------------------------------------------------------------------------------------------------
 * Blurb:
 * I encountered a few issues that caused the program to loop incorrectly and behave unpredictably. 
 * assignment operator (=) instead of the equality operator (==) in the conditional checks for the month and year
 * which caused the loops to run indefinitely, Repeated (Cout) "what year do you want me to look at?"
 * Another issue was the incorrect use of the & operator instead of the logical AND operator (&&) when checking if the year input was valid. 
 * This caused the program to incorrectly accept invalid input, like negative years. 
 * Lastly, I didn’t properly check if the month input was within the correct range (1-12)
 * ------------------------------------------------------------------------------------------------------------------------------------------
 */

#include <iostream>
#include <conio.h>
#include <string>
#include <limits>

using namespace std;

//  -------------------------------------------------------------------------------------------------------
//  This program uses enums for case/switch in a user-defined function to find how many days are in a month.
//  Year is required to find how many days are in a leap year.
//  There are 4 errors in this code, can you find them?  Hint: one is a mathematics error.
//  -------------------------------------------------------------------------------------------------------

//  Assigns enum for months, starting with 1 not 0
enum Months {january = 1, february, march, april, may, june, july, august, september, october, november, december };

//  Declares user-defined function for use after main
int DaysInMonth(Months month, int year);

//  Main program
int main(){
    //  Declare variables
    bool result = true; 
    int user_input_month, user_input_year;
    string months_arr[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    //  Welcoming message
    cout << "\n\n  Welcome to my program.";
    cout << "\n  -----------------------";
    cout << "\n  I can tell you how many days are in any month.";
    
    //  User input for month with error checking
    do {
        cout << "\n  What month do you want me to look at(1-12)? ";
        cin >> user_input_month;
        if (user_input_month >= january && user_input_month <= december) {
            result = false;
        }
        else {
            cout << "\n  Please enter a correct month (1-12).";
        }
    } while (result == true);                                                                 // Fixed: condition should be '== true' for the loop to end correctly
    
    //  User input for year in case of input for February
    do {
        cout << "\n  What year do you want me to look at (> 1AD)? ";
        cin >> user_input_year;
        
        // Check if the input is valid (integer) and greater than 0
        if (cin.fail() || user_input_year <= 0) { 
            cin.clear();  // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignore invalid input
            cout << "\n  Please enter a valid year.";
        }
        else {
            result = false;  // Exit the loop if the input is valid
        }
    } while (result == true);                                                                 // Fixed: condition should be '== true' for the loop to exit on valid year
    
    //  Using static cast to convert user input to enums for function
    Months selected_month = static_cast<Months>(user_input_month);

    //  Program output to user
    cout << "\n\n  There are " << DaysInMonth(selected_month, user_input_year);
    cout << " days in " << months_arr[user_input_month - 1] << ", " << user_input_year << endl;
    cout << "\n\n  Press any key to continue...";
    (void)_getch();
    return 0;
}

//  Function to find days in month
int DaysInMonth(Months month, int year) {
    switch (month) {
        case april: case june: case september: case november:
            return 30;
        case february: 
          
            if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))                    // Fixed: Corrected leap year check
                return 29;
            return 28;
        default: // All other months
            return 31;
    }
}
