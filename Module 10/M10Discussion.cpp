#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *ptr;
 
    cout << "Value at ptr: " << *ptr << endl;

    int *ptr2 = &b;
    cout << "Value at ptr2: " << *ptr2 << endl;

    return 0;
}
