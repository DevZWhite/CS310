/*
 * Created by Randy Easton on 3/10/2025.
 * Revised on 05/21/2025 For Discussion Board 11
 * Reviewed and fixed by Zachary White 05/25/2025
*/

/* When I reviewed the original C++ code, I noticed a few issues that needed to be fixed to get it running properly. 
 * The first problem was with the template function calc_interest—it used incorrect syntax (template <T>), 
 * so I corrected it to template <typename T>. I also saw that the function was being called with a string type, which didn’t make sense since the inputs were double values. 
 * I changed the call to use double instead. The output formatting also needed attention. 
 * The code attempted to use std::put_money, but that can be inconsistent depending on the system and locale settings. 
 * I added a fallback using fixed and setprecision to ensure the interest is displayed correctly as currency. 
 * I also cleaned up the locale handling by trying to apply "en_US.UTF-8" and adding a backup formatting method. 
 * Lastly, I added return 0; at the end of main() to follow best practices.
 */

#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

// Fixed template syntax
template <typename T>
T calc_interest(T calcADB, T interestRate) {
    if (interestRate < 1) {
        return calcADB * interestRate;
    } else {
        return calcADB * interestRate / 100;
    }
}

int main() {
    // Variables
    double dblNetbalance = 0;
    double dblPayment = 0;
    double dblBillCycleDays = 0; // D1
    double dblPaymentDays = 0;   // D2
    double dblInterestRate = 0;

    // Inputs
    cout << "What is the Current Balance on your Bill? ";
    cin >> dblNetbalance;
    cout << "How much did you pay on this month's Bill? ";
    cin >> dblPayment;
    cout << "How many days are in your billing cycle? ";
    cin >> dblBillCycleDays;
    cout << "At the time you made the payment, how many days were left in the cycle? ";
    cin >> dblPaymentDays;
    cout << "What is the interest rate (as a % or decimal)? ";
    cin >> dblInterestRate;

    // Calculations
    double calcAverageDailyBalance =
        (dblNetbalance * dblBillCycleDays - dblPayment * dblPaymentDays) / dblBillCycleDays;
    double DisplayInterest = calc_interest<double>(calcAverageDailyBalance, dblInterestRate);

    // Output
    try {
        cout.imbue(locale("en_US.UTF-8"));
        cout << "The interest you paid was: $" << fixed << setprecision(2) << DisplayInterest << endl;
    } catch (...) {
        // Fallback if locale fails
        struct group_facet : public std::numpunct<char> {
        protected:
            string do_grouping() const override { return "\003"; }
        };
        cout.imbue(locale(cout.getloc(), new group_facet));
        cout << "The interest you paid was: $" << fixed << setprecision(2) << DisplayInterest << endl;
    }

    return 0;
}
