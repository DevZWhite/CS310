/*
* Original Submission by: Kevin Marler
* Solution By: Zachary White
* Date: 05/02/2025
*/

#include <iostream>
#include <string> // Corrected the header file

class thePoof {
public:
  std::string name;
  std::string breed;
  thePoof(std::string dogName, std::string dogBreed) : name(dogName), breed(dogBreed) {}
  
  void bark() {
    std::cout << "Woof! My name is " << name << " and I am a " << breed << std::endl;
  }
};

class InfamousMe {
public:
  std::string name;
  thePoof dog;

  InfamousMe(std::string infamousOne, thePoof infamousPoof) : name(infamousOne), dog(infamousPoof) {}

  void introduceDog() {
    std::cout << "My name is " << name << " and this is my dog " << dog.name << ", a " << dog.breed << std::endl;
    dog.bark();
  }
};

int main() {
  thePoof myDog("Loki", "Husky");
  InfamousMe myOwner("Kevin", myDog);

  myOwner.introduceDog(); // Fixed method call

  return 0;
}
