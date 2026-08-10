#include <iostream>

int main() {
	int age = 22;

	// & means give me the address of the variable
	int* agePointer = &age;

	std::cout << "Value of age: " << age << std::endl;
	std::cout << "Address of age: " << &age << std::endl;
	std::cout << "Value stored in agePointer: " << agePointer << std::endl;

	// * means dereference, to go to the address and get the value stored there
	std::cout << "Value pointed to by agePointer: " << *agePointer << std::endl;

	// Changing the value through the pointer changes the original variable
	*agePointer = 30;
	std::cout << "Age is now: " << age << std::endl;

	return 0;
}