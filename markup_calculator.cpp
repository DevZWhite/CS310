#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double originalPrice, markupPercentage, salesTaxRate;
    
    // Get user input
    cout << "Enter the original price of the item: ";
    cin >> originalPrice;
    
    cout << "Enter the markup percentage (as a whole number, e.g., 20 for 20%): ";
    cin >> markupPercentage;
    
    cout << "Enter the sales tax rate (as a whole number, e.g., 7 for 7%): ";
    cin >> salesTaxRate;

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

    return 0;
}
