// Zachary D. White.
// Tested Windows 11 : Windows Virtual Studio Code.
// The program establishes and uses enumeration values.
// The program compiles but has 2 errors.
// issue Hint: Enumeration Declaration and Syntax.
// You may also clean up logic if you are interested in completing the enumeration values.

#include <iostream>
using namespace std;

enum Color { RED, GREEN, BLUE };

int main() {
    Color myColor = YELLOW;

    if (mycolor == RED) {
        cout << "The color is red." << endl;
    }

    return 0;
}
