#include <iostream>
using namespace std;

int main() {
    int score, level;
    string grade, levelText;

    cout << "Enter your test score: " << endl;
    cin >> score;

    if (score >= 90) {
        grade = "A";
    }
    else if (score >= 80) { // Removed redundant "&& score < 90"
        grade = "B";
    }
    else { // Added missing closing bracket for else-if block
        grade = "Below B";
    }

    cout << "Enter your academic level (1 = Freshman, 2 = Sophomore, 3 = Junior, 4 = Senior): ";
    cin >> level;

    switch(level) {
        case 1:
            levelText = "Freshman";
            break;
        case 2:
            levelText = "Sophomore";
            break;
        case 3:
            levelText = "Junior";
            break;
        case 4:
            levelText = "Senior";
            break; // Added missing break statement
        default:
            levelText = "Unknown";
            cout << "Invalid level input." << endl;
    }

    cout << "\nYou are a " << levelText << " and your grade is: " << grade << "." << endl;

    return 0;
}
