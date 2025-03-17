#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    char choice;
    
    do {
        double originalPrice, markupPercentage, salesTaxRate;

        // Get user input
        cout << "Enter the original price of the item: ";
        while (!(cin >> originalPrice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number: ";
        }

        cout << "Enter the markup percentage (as a whole number, e.g., 20 for 20%): ";
        while (!(cin >> markupPercentage)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number: ";
        }

        cout << "Enter the sales tax rate (as a whole number, e.g., 7 for 7%): ";
        while (!(cin >> salesTaxRate)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number: ";
        }

        // Convert percentage values to decimal
        double markupAmount = originalPrice * (markupPercentage / 100);
        double sellingPrice = originalPrice + markupAmount;
        double salesTax = sellingPrice * (salesTaxRate / 100);
        double finalPrice = sellingPrice + salesTax;

        // Display results
        cout << fixed << setprecision(2);
        cout << "\nOriginal Price: $" << originalPrice << endl;
        cout << "Markup Percentage: " << markupPercentage << "%" << endl;
        cout << "Selling Price: $" << sellingPrice << endl;
        cout << "Sales Tax Rate: " << salesTaxRate << "%" << endl;
        cout << "Sales Tax: $" << salesTax << endl;
        cout << "Final Price: $" << finalPrice << endl;

        // Ask if the user wants to run the program again
        cout << "\nWould you like to calculate another price? (y/n): ";
        cin >> choice;

        // Validate input for y/n choice
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Invalid choice. Enter 'y' to continue or 'n' to exit: ";
            cin >> choice;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

    } while (choice == 'y' || choice == 'Y');

    if (choice =='n'|| choice == 'N');
    {
        cout << "Goodbye!\n";
        system("pause");  // Prevents immediate closure
    }

 return 0;

}
