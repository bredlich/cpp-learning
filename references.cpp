#include <iostream>

int main() {
	int age = 22;

	// & here means something different, this declares a reference not a pointer
	int& ageRef = age;

	std::cout << "age: " << age << std::endl;
	std::cout << "ageRef: " << ageRef << std::endl;

	// Changing ageRef changes age directly, no dereferencing unlike a pointer
	ageRef = 30;
	std::cout << "age is now: " << age << std::endl; 

	return 0;
}