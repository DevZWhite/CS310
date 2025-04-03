#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

// Constants
const double FIXED_ADVANCE = 5000.0;
const double FIXED_PUBLICATION_PAYMENT = 20000.0;
const double ROYALTY_RATE_OPTION_2 = 0.125;
const double ROYALTY_RATE_OPTION_3_LOW = 0.10;
const double ROYALTY_RATE_OPTION_3_HIGH = 0.14;
const int SALES_THRESHOLD = 4000;

void calculateRoyalties(double netPrice, int estimatedSales) {
    // Option 1: Fixed Payment
    double option1Royalties = FIXED_ADVANCE + FIXED_PUBLICATION_PAYMENT;

    // Option 2: Flat 12.5% of net price per copy
    double option2Royalties = estimatedSales * netPrice * ROYALTY_RATE_OPTION_2;

    // Option 3: Tiered royalties
    double option3Royalties;
    if (estimatedSales <= SALES_THRESHOLD) {
        option3Royalties = estimatedSales * netPrice * ROYALTY_RATE_OPTION_3_LOW;
    } else {
        option3Royalties = (SALES_THRESHOLD * netPrice * ROYALTY_RATE_OPTION_3_LOW) +
                           ((estimatedSales - SALES_THRESHOLD) * netPrice * ROYALTY_RATE_OPTION_3_HIGH);
    }

    // Determine best option
    map<string, double> royalties = {
        {"Option 1", option1Royalties},
        {"Option 2", option2Royalties},
        {"Option 3", option3Royalties}
    };

    string bestOption;
    double maxRoyalties = 0.0;
    for (const auto& option : royalties) {
        if (option.second > maxRoyalties) {
            maxRoyalties = option.second;
            bestOption = option.first;
        }
    }

    // Output results
    cout << "\nRoyalty Earnings:" << endl;
    cout << fixed << setprecision(2);
    for (const auto& option : royalties) {
        cout << option.first << ": $" << option.second << endl;
    }

    cout << "\nBest Option: " << bestOption << " with earnings of $" << maxRoyalties << endl;
}

int main() {
    double netPrice;
    int estimatedSales;

    // Get user input
    cout << "Enter the net price of each copy of the novel: ";
    cin >> netPrice;
    cout << "Enter the estimated number of copies that will be sold: ";
    cin >> estimatedSales;

    // Calculate royalties
    calculateRoyalties(netPrice, estimatedSales);
    
    return 0;
}
