/*
 * Name: Zachary White
 * Course: CS310
 * Intructor: Dr. Robert Flowers
 * Assignment: Bank Accounts
 */

/*
 * This app manages bank accounts. 
 * Users can create accounts, deposit, withdraw, and apply interest. 
 * It supports checking and saving accounts. 
 * Transactions are validated. 
 * Account details are displayed. 
 * Account numbers are auto-assigned.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class bankAccount {
private:
    string name;
    int accountNumber;
    string accountType; // "checking" or "saving"
    double balance;
    double interestRate; // stored as decimal
    static int nextAccountNumber; // static member to auto-assign account numbers

public:
    // Default constructor
    bankAccount() : name(""), accountType(""), balance(0.0), interestRate(0.0) {
        accountNumber = nextAccountNumber++;
    }

    // Parameterized constructor
    bankAccount(string accName, string accType, double accBalance, double rate)
        : name(accName), accountType(accType), balance(accBalance), interestRate(rate) {
        accountNumber = nextAccountNumber++;
    }

    // Function to set account details
    void setAccountDetails(string accName, string accType, double accBalance, double rate) {
        name = accName;
        accountType = accType;
        balance = accBalance;
        interestRate = rate;
        accountNumber = nextAccountNumber++;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " to account #" << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from account #" << accountNumber << endl;
        } else {
            cout << "Invalid or insufficient funds for withdrawal." << endl;
        }
    }

    void applyInterest() {
        balance += balance * interestRate;
        cout << "Interest applied to account #" << accountNumber << endl;
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        cout << "-----------------------------" << endl;
    }
};

// Initialize static member
int bankAccount::nextAccountNumber = 1001;

// Main program to demonstrate class
int main() {
    const int SIZE = 10;
    bankAccount customers[SIZE];

    // Creating some sample accounts
    customers[0].setAccountDetails("Alice Smith", "checking", 1500.00, 0.02);
    customers[1].setAccountDetails("Bob Johnson", "saving", 2300.50, 0.03);

    // Performing some operations
    customers[0].deposit(500.00);
    customers[1].withdraw(200.00);
    customers[0].applyInterest();

    // Display all customer accounts
    for (int i = 0; i < 2; ++i) {
        customers[i].display();
    }

    return 0;
}
