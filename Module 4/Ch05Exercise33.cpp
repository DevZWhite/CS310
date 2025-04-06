// Student Name: Zachary White
// Date: 03/31/2025
// Description:
// (a) represents how many minutes it takes to prepare the first dish.
// (b) represents how many minutes longer the next dish will take than the first.
// (t) is the total time to prepare dishes
// the application uses these variables to show how many dishes can be prepared.

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Function to get validated input this avoids looping indefinitely 
// I wanted a better user experience, so opted for displaying invalid input text.
// When the user inputs "0" the system returns "Please enter a whole number greather than 0."
int Validinput(const string& prompt, int minValue) {
    int input;
    cout << prompt << endl;
    while (!(cin >> input) || input < minValue) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a whole number";
        if (minValue > 0)
            cout << " greater than " << minValue - 1;
        cout << ":" << endl;
    }
    return input;
}

int main() {
    // Using valid input helped cut down logic bloat 
    int a = Validinput("How many minutes does it take Bianca to prepare the first dish?", 1);
    int b = Validinput("How many more minutes does each following dish take?", 0);
    int t = Validinput("How many minutes does Bianca have to prepare dishes?", 0);

    // encountered an error innitially when running my application
    // If the first dish takes longer than the total time the user is displayed the following
    // "Bianca does not have time to prepare any dishes."
    if (a > t) {
        cout << "Not enough time to prepare any dishes" << endl;
        return 0;
    }

    int remainingTime = t - a;
    int dishesPrepared = 1;
    int nextDishTime = a;

    while (true) {
        nextDishTime += b;
        if (nextDishTime <= remainingTime) {
            dishesPrepared++;
            remainingTime -= nextDishTime;
        } else {
            break;
        }
    }

    // Outputs the result after calculation
    // this helps the system return results by, allowing for dish(es)
    if (dishesPrepared == 1) {
        cout << "Bianca can only prepare one dish." << endl;
    } else {
        cout << "Bianca can prepare " << dishesPrepared << " dishes." << endl;
    }

    return 0;
}
