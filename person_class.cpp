#include <iostream>
#include <string>

class Person {
public:
    // Member variables, the data every Person object will have
    std::string name;
    int age;

    // Constructor, runs automatically when a Person is created
    Person(std::string personName, int personAge) {
        name = personName;
        age = personAge;
        std::cout << "A new Person object was created: " << name << std::endl;
    }

    // A member function, behavior that belongs to Person
    void introduce() {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old." << std::endl;
    }
};

int main() {
    // Creating two Person objects, the constructor runs for each
    Person alice("Alice", 30);
    Person bob("Bob", 25);

    alice.introduce();
    bob.introduce();

    // Directly accessing member variables
    std::cout << alice.name << " is " << alice.age << std::endl;

    return 0;
}
