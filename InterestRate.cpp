#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main() {
    // Declare variables
    double netBalance, payment, interestRate, averageDailyBalance, interest;
    int d1, d2;

    // Get user input
    cout << "Enter net balance: ";
    cin >> netBalance;
    cout << "Enter payment made: ";
    cin >> payment;
    cout << "Enter number of days in the billing cycle: ";
    cin >> d1;
    cout << "Enter number of days before the billing cycle the payment was made: ";
    cin >> d2;
    cout << "Enter interest rate per month (e.g., 0.0152 for 1.52%): ";
    cin >> interestRate;

    // Compute the average daily balance
    averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

    // Compute the interest
    interest = averageDailyBalance * interestRate;

    // Format and display the interest
    cout << fixed << setprecision(2); // Set decimal precision to 2 places
    locale loc(""); // Use default system locale for thousands separator
    cout.imbue(loc);
    
    cout << "Interest on the unpaid balance: $" << interest << endl;

    return 0;
}
