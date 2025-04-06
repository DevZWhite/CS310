#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main() {
	string name, input;
	int number, sum = 0;

	cout << "\n\n  Welcome to my program";
	cout << " \n  ---------------------";
	cout << "\n\n  What is your name? ";
	getline(cin, name);

	cout << "\n  " << name << ", I can help add integer numbers for you.\n";

	while (true) {
		cout << "  Enter a number or press x to see the sum: ";
		cin >> input;

		if (input == "x") {
			break;
		}

		// Error handling can be added here for invalid input
		number = stoi(input);
		sum = sum + number;
	}

	cout << "\n\n  The sum of the numbers entered is: " << sum;
	cout << "\n  Thanks for using my program.  Press any key to continue.";
	_getch();
}
