#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b
}

template <class T>
class Container {
public:
    Container(T val) : value(val) {}
    
    void display() const {
        cout << "Value: " << valu << endl; // Error: 'valu' should be 'value'
    }

private:
    T value;
};

int main() {
    cout << "Result: " << add(5, 10) << endl;

    Container<int> box(42);
    box.display();

    return 0;
}
