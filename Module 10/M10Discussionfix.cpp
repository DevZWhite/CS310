/* Created by Norman Cervantes
 * CS310 - Module 10 Discussion
 * Fixed by: Zachary White
 * Date: 05/17/2025
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    int numbers[3] = { 10, 20, 30 };
    int* ptr = numbers;

    for (int i = 0; i < 3; ++i) {
        cout << "Value at index " << i << ": " << *(ptr + i) << endl;
    }

    // Removed uninitialized pointer usage to avoid undefined behavior
    // int* uninitializedPtr;
    // cout << "Random value: " << *uninitializedPtr << endl;

    string name = "Norman";
    void* genericPtr = &name;

    // You cannot do pointer arithmetic on void*
    // If you want to increment the pointer, cast it to char* (byte pointer)
    genericPtr = static_cast<char*>(genericPtr) + 1;

    // 'missingRate' is undefined, so we need to define it before using
    double missingRate = 0.05;
    double* ratePtr = &missingRate;

    string message = "Module 10 complete";

    cout << message << endl;

    return 0;
}
