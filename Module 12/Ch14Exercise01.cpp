#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>

using namespace std;

// Exception for negative numbers
class NegativeNumber : public exception {
public:
    const char* what() const noexcept override {
        return "Negative numbers are not allowed.";
    }
};

// Exception for non-numeric input
class NonNumber : public exception {
public:
    const char* what() const noexcept override {
        return "Input must be a valid number.";
    }
};

// Function to get a validated float from the user
float getValidatedInput(const string& prompt) {
    string input;
    float value;

    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);

        if (!(ss >> value) || !(ss.eof())) {
            cout << "Error: ";
            throw NonNumber();
        }

        if (value < 0) {
            cout << "Error: ";
            throw NegativeNumber();
        }

        return value;
    }
}

int main() {
    float feet = 0.0, inches = 0.0;

    while (true) {
        try {
            feet = getValidatedInput("Enter feet: ");
            inches = getValidatedInput("Enter inches: ");

            // Convert to centimeters
            float totalInches = (feet * 12) + inches;
            float centimeters = totalInches * 2.54;

            cout << "Equivalent length in centimeters: " << centimeters << " cm" << endl;
            break; // exit the loop if input is valid

        } catch (const NonNumber& e) {
            cout << e.what() << " Please try again.\n";
        } catch (const NegativeNumber& e) {
            cout << e.what() << " Please try again.\n";
        }
    }

    return 0;
}
