#include <iostream>
#include <string>

class Animal {
public:
    std::string name;

    Animal(std::string animalName) {
        name = animalName;
    }

    void eat() {
        std::cout << name << " is eating." << std::endl;
    }
};

// Dog inherits everything Animal has, plus its own additions
class Dog : public Animal {
public:
    Dog(std::string dogName) : Animal(dogName) { // calls Animal's constructor first
    }

    void bark() {
        std::cout << name << " says woof!" << std::endl; // "name" comes from Animal
    }
};

int main() {
    Dog rex("Rex");
    rex.eat();  // inherited from Animal
    rex.bark(); // Dog's own function

    return 0;
}
