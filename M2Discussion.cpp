// Corrected Code
// Added missing semicolon (;) after cin >> originalPrice
// Changed cout >> to cout << for correct output syntax
// Fixed the missing semicolon (;) after defining constants
// Original Code https://github.com/zach-cs-bellevue/CS310/blob/2643eb2244499f22f3c3f5b7d1f5dca13586f4e6/M2%20Discussion.cpp

#include <iostream>
using namespace std;

int main()
{
    const double SALES_TAX_RATE = 6.0, markupPercent = 2.2;
    double originalPrice, sellingPrice, salesTax, finalPrice;

    // Input
    cout << "Enter the original price of item: $ ";
    cin >> originalPrice;  // Added missing semicolon

    // Calculations
    sellingPrice = originalPrice + (originalPrice * markupPercent / 100);
    salesTax = sellingPrice * SALES_TAX_RATE / 100;
    finalPrice = sellingPrice + salesTax;

    // Output
    cout << "Original price of the item: $ " << originalPrice << endl;
    cout << "Percentage of the marked-up price: " << markupPercent << "%" << endl;
    cout << "Store selling price: $ " << sellingPrice << endl;
    cout << "Sales tax rate: " << SALES_TAX_RATE << "%" << endl;
    cout << "Sales tax: $ " << salesTax << endl;
    cout << "Final price of the item: $ " << finalPrice << endl;

    return 0;
}
