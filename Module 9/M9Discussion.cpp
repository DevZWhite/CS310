#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {
        cout << "Some animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Woof!" << endl
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    dog.speak();
    cat.speek();

    return 0;
}
