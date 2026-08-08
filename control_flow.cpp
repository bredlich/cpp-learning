#include <iostream>

// Simple function: take a number and return wether it's even
bool isEven(int number) {
	return number % 2 == 0;
}

// A function with no return value (void)
void describeNumber(int number) {
	if (number < 0) {
		std::cout << number << " is negative." << std::endl;
	}
	else if (number == 0) {
		std::cout << number << " is zero." << std::endl;
	}
	else {
		std::cout << number << " is positive." << std::endl;
	}
}

int main() {
	// A for loop - print numbers 1 to 5 and wether each are even
	for (int i = 1; i <= 5; i++) {
		if (isEven(i)) {
			std::cout << i << " is even." << std::endl;
		}
		else {
			std::cout << i << " is odd." << std::endl;
		}
	}

std::cout << std::endl;

// Using th describeNumber funtion
describeNumber(-3);
describeNumber(0);
describeNumber(7);

return 0;
}