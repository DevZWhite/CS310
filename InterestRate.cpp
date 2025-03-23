#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Function to format numbers with thousands separators manually
string formatWithThousandsSeparator(double value) {
    stringstream ss;
    ss << fixed << setprecision(2) << value;
    string numStr = ss.str();
    int pos = numStr.find('.');
    int insertPos = pos - 3;

    while (insertPos > 0) {
        numStr.insert(insertPos, ",");
        insertPos -= 3;
    }

    return numStr;
}

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

    // Manually format and display the interest
    cout << "Interest on the unpaid balance: $" << formatWithThousandsSeparator(interest) << endl;

    return 0;
}
