#include <iostream>

using namespace std;

int main() {
    int matrix[3][3];  // Declaring a 3x3 matrix

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            matrix[row][col] = i + col;
    }
    
    cout << "Element at (3,3): " << matrix[3][3] << endl; 

    return 0;
}
