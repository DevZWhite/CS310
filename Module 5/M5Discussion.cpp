#include <iostream>
using namespace std;

// Primary function to calculate the area
int calculateArea(int length, int width) {
    return length * width;
}

// Secondary to display results
void displayResult(int area) {
    cout << "The area of the rectangle is: " << area << endl
}

int main() {
    int l, w;
    cout << "Please enter the length of the rectangle: ";
    cin >> l;
    cout << "Pleas enter the width of the rectangle: ";
    cin << w;

    int area = calculatearea(l, w);
    displayResult(area);

    return 0;
}
