/*
 * Name: Zachary White
 * Course: CS310
 * Assignment: Bank / checking / savings. parts 1 2 3 are all compiled within the same program
 */

/*
 * This program uses class and inheritance to build the following structures.
 * Bank accounts, Checking accounts and Savings accounts.
 * We then use simple test string programs to store data and print results for our structures.
 * There is no current function to input data for the user. ( can create one if interested. )
 * all data printed from test is provided from stored memory within the program during main.
 */

#include <iostream>
using namespace std;

class bankAccount {
protected:
    int accountNumber;
    double balance;

public:
    // Constructs the account
    bankAccount(int acctNumber = 0, double initialBalance = 0.0)
        : accountNumber(acctNumber), balance(initialBalance) {}

    // Sets the account number
    void setAccountNumber(int acctNumber) {
        accountNumber = acctNumber;
    }

    void setBalance(double newBalance) {
        balance = newBalance;
    }

    // Get account number, retrieves account number
    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Withdraw money
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    // Prints account information The latter testing of said account will be filled using a string
    virtual void printAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minimumBalance;
    double serviceCharge;

public:
    // Construct checking account
    checkingAccount(int acctNumber = 0, double initialBalance = 0.0, 
                    double interest = 0.0, double minBalance = 0.0, 
                    double charge = 0.0)
        : bankAccount(acctNumber, initialBalance), interestRate(interest), 
          minimumBalance(minBalance), serviceCharge(charge) {}

    // Set interest rate
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    void setMinimumBalance(double minBalance) {
        minimumBalance = minBalance;
    }

    void setServiceCharge(double charge) {
        serviceCharge = charge;
    }

    // Get interest rate
    double getInterestRate() const {
        return interestRate;
    }

    double getMinimumBalance() const {
        return minimumBalance;
    }

    double getServiceCharge() const {
        return serviceCharge;
    }

    // Post interest
    void postInterest() {
        balance += balance * interestRate / 100;
    }

    // Verify the account minimum balance requirements
    bool isBelowMinimumBalance() const {
        return balance < minimumBalance;
    }

    // Writes a check
    void writeCheck(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient funds to write check." << endl;
        }
    }

    // Withdraws amount
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            if (balance < minimumBalance) {
                balance -= serviceCharge; // Apply service charge
            }
        }
    }

    // Prints account information
    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance: $" << minimumBalance << endl;
        cout << "Service Charge: $" << serviceCharge << endl;
    }
};

class savingsAccount : public bankAccount {
private:
    double interestRate;

public:
    // Constructs savings account
    savingsAccount(int acctNumber = 0, double initialBalance = 0.0, double interest = 0.0)
        : bankAccount(acctNumber, initialBalance), interestRate(interest) {}

    // Sets interest rate, showcasing the reuse of code from prior iterations
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    // Gets interst rate
    double getInterestRate() const {
        return interestRate;
    }

    // Posts interest rates
    void postInterest() {
        balance += balance * interestRate / 100;
    }

    // Withdraws amount
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    // Prints the account information
    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    /*
    * Creates bankAccount object
    * Runs test for all 3 categories for account/checking/savings
    */ 
    bankAccount account1(1001, 500.0);
    account1.deposit(200.0);
    account1.withdraw(100.0);
    account1.printAccountInfo();

    cout << "\n------------------\n";

    // Create checkingAccount object
    checkingAccount checking1(2001, 1500.0, 3.0, 100.0, 15.0);
    checking1.deposit(500.0);
    checking1.writeCheck(200.0);
    checking1.withdraw(1000.0); // Below minimum balance, service charge applied
    checking1.postInterest();
    checking1.printAccountInfo();

    cout << "\n------------------\n";

    // Create savingsAccount object
    savingsAccount savings1(3001, 1000.0, 2.5);
    savings1.deposit(300.0);
    savings1.withdraw(100.0);
    savings1.postInterest();
    savings1.printAccountInfo();

    return 0;
}
