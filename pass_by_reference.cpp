#include <iostream>

// Pass by value - function get a copy, orignal variable is not changed
void addTenByValue(int number) {
	number = number + 10;
	std::cout << "Inside addByTenValue: " << number << std::endl;
}

// Pass by reference - function works on original variable
void addTenByReference(int& number) {
	number = number + 10;
	std::cout << "Inside addByTenReference: " << number << std::endl; 
}

int main() {
	int a = 5;
	addTenByValue(a);
	std::cout << "After addByTenValue: " << a << std::endl; // a is still 5

	int b = 5;
	addTenByReference(b);
	std::cout << "After addByTenReference: " << b << std::endl; // b is now 15

	return 0;
}