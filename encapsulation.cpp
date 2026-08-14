#include <iostream>
#include <string>

class Person {
private:
    // Now hidden from outside the clas, can't be accessed directly as person.age
    std::string name;
    int age;

public:
    Person(std::string personName, int personAge) {
        name = personName;
        setAge(personAge); // uses the setter below, so validation applies even in the constructor
    }

    // Getter, controlled read access
    int getAge() {
        return age;
    }

    // Setter, controlled write access with validation
    void setAge(int newAge) {
        if (newAge < 0 || newAge > 150) {
            std::cout << "Invalid age, ignoring." << std::endl;
            return;
        }
        age = newAge;
    }

    std::string getName() {
        return name;
    }

    void introduce() {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old." << std::endl;
    }
};

int main() {
    Person alice("Alice", 30);
    alice.introduce();

    // alice.age = -5;      // this would now fail to compile, age is private
    alice.setAge(-5);       // this compiles, but the validation inside setAge rejects it
    alice.introduce();      // age is still 30, the invalid value was ignored

    alice.setAge(31);
    alice.introduce();      // now correctly updated

    std::cout << "Getting age directly: " << alice.getAge() << std::endl;

    return 0;
}
