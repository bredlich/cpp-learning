#include <iostream>
#include <string>

int main() {
	int age = 25; // Integer variable
	double price = 19.99; // Double variable
	char grade = 'A'; // Single character variable, single quotes
	bool isStudent = true; // Boolean variable true/false
	std::string name = "Alex"; // text double quotes

	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Grade: " << grade << std::endl;
	std::cout << "Is Student: " << isStudent << std::endl;

	return 0;
}