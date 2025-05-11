/*
* Original Submission by: Zachary Eaton
* Solution By: Zachary White
* Date: 05/11/2025
*/

/*
____________________________________Synopsis________________________________________
* This C++ program demonstrates the use of inheritance and polymorphism 
* by modeling a basic character system in a role-playing game. 
* The program defines a base class Character, with derived classes Sorcerer
* Druid, and Rogue representing different character types. 
* Each class has a displayInfo() method that outputs the character’s name
* level, class, and primary ability. The displayInfo() method is overridden 
* in the derived classes to include specific details related to the character's
* abilities. This program showcases how derived classes can extend the functionality 
* of a base class and provide specific behavior while maintaining a common interface. 
*/

#include <iostream>
#include <string>
using namespace std;

// Base class
class Character {
protected:
    string name;
    int level;
    string class_name;

public:
    // Constructor to initialize the character details
    Character(string n, int l, string c) : name(n), level(l), class_name(c) {}

    // Display character info
    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Class: " << class_name << endl;
    }
};

// Child class: Sorcerer
class Sorcerer : public Character {
public:
    // Constructor initializes with class name "Sorcerer"
    Sorcerer(string n, int l) : Character(n, l, "Sorcerer") {}

    // Display info for Sorcerer, overriding the base class method
    void displayInfo() const override {
        Character::displayInfo();
        cout << "Primary Ability: Charisma" << endl;
    }
};

// Child class: Druid
class Druid : public Character {
public:
    // Constructor initializes with class name "Druid"
    Druid(string n, int l) : Character(n, l, "Druid") {}

    // Display info for Druid, overriding the base class method
    void displayInfo() const override {
        Character::displayInfo();
        cout << "Primary Ability: Wisdom" << endl;
    }
};

// Child class: Rogue
class Rogue : public Character {
public:
    // Constructor initializes with class name "Rogue"
    Rogue(string n, int l) : Character(n, l, "Rogue") {}

    // Display info for Rogue, overriding the base class method
    void displayInfo() const override {
        Character::displayInfo();
        cout << "Primary Ability: Dexterity" << endl;
    }
};

int main() {
    // Create characters
    Sorcerer sorcerer("Zoey", 11);
    Druid druid("Aine", 6);
    Rogue rogue("Faye", 4);

    // Display character info
    cout << "\nCharacter Info:" << endl;
    sorcerer.displayInfo();
    cout << endl;
    druid.displayInfo();
    cout << endl;
    rogue.displayInfo();
    cout << endl;

    return 0;
}
