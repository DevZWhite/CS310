#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {
        cout << "The animal makes a sound." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Animal a;
    Dog d;

    a.speak();
    d.speak();

    cat.speak();

    d.speakk();

    return 0;
}
