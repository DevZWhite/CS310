// Student Name: Zachary White
// Date: 04/08/2025
// Description:
// The user enters the hourly rate, the total consulting time, and whether the person has low income. 
// The program should output the billing amount.
// Extra abilties such as entering multiple clients, rounding numbers with setprecision, and

// Tested on Windows 11, Visual Studio Code

#include <iostream>
#include <iomanip> 

using namespace std;

// Function used to calculate biling amount based on income.
double calculateBilling(double hourlyRate, int consultingMinutes, bool isLowIncome) {
double billingAmount = 0.0;

    if (isLowIncome) {
      if (consultingMinutes > 30) {
        int chargeableMinutes = consultingMinutes - 30;
            billingAmount = hourlyRate * 0.40 * (chargeableMinutes / 60.0);
        }
   } else {
      if (consultingMinutes > 20) {
       int chargeableMinutes = consultingMinutes - 20;
            billingAmount = hourlyRate * 0.70 * (chargeableMinutes / 60.0);
        }
    }

    return billingAmount;
}

int main() {
    double hourlyRate;
    char continueOption;
    int clientCount = 1;

    // Input hourly rate with input validation that I learned from a peer this week Eric Zimmer thanks for the references.
    do {
        cout << "Enter hourly rate (greater than 0): $";
        cin >> hourlyRate;
        if (hourlyRate <= 0) {
            cout << "Invalid input. Please enter a positive hourly rate." << endl;
        }
    } while (hourlyRate <= 0);

    // Added ability to process multiple clients, without terminating the application.
    do {
        cout << "\nProcessing client #" << clientCount << ":\n";

        int hours, minutes;
        char incomeStatus;
        bool isLowIncome;

        // Input consulting time, this adds the ability to enter hours or minutes to make consultation tracking more exact.
        do {
            cout << "Enter consulting time - hours: ";
            cin >> hours;
            if (hours < 0) {
                cout << "Invalid input. Hours cannot be negative." << endl;
            }
        } while (hours < 0);

        do {
            cout << "Enter consulting time - minutes (0 to 59): ";
            cin >> minutes;
            if (minutes < 0 || minutes >= 60) {
                cout << "Invalid input. Minutes must be between 0 and 59." << endl;
            }
        } while (minutes < 0 || minutes >= 60);

        int totalMinutes = hours * 60 + minutes;

        // Input income status... I arguably couldnt figure out how to calculate if someone were to have income so I left it as a simple question.
        do {
            cout << "Does the person have low income? (y/n): ";
            cin >> incomeStatus;
            incomeStatus = tolower(incomeStatus);
            if (incomeStatus != 'y' && incomeStatus != 'n') {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            }
        } while (incomeStatus != 'y' && incomeStatus != 'n');

        isLowIncome = (incomeStatus == 'y');

        // Calculate and display billing amount (rounded to 2 decimal places)... 
        // I kept having my thousandths place become visible, used setprecision to fix this.
        double billingAmount = calculateBilling(hourlyRate, totalMinutes, isLowIncome);
        cout << fixed << setprecision(2);
        cout << "The billing amount is: $" << billingAmount << endl;

        // Ask if the user wants to process another client?
        do {
            cout << "\nDo you want to process another client? (y/n): ";
            cin >> continueOption;
            continueOption = tolower(continueOption);
            if (continueOption != 'y' && continueOption != 'n') {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            }
        } while (continueOption != 'y' && continueOption != 'n');

        clientCount++;

    } while (continueOption == 'y');

    // thanking the user for using the application before terminating.

    cout << "\nThank you for using the J&J billing system. Goodbye!" << endl;
    return 0;
}
