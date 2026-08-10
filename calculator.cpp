#include <iostream>
#include <string>

// A function for each operation - keeps main() clean and readable
double add(double a, double b) {
	return a + b;
}
double subtract(double a, double b) {
	return a - b;
}
double multiply(double a, double b) {
	return a * b;
}

double divide(double a, double b) {
	if (b == 0) {
		std::cerr << "Error: Division by zero!" << std::endl;
		return 0; // Return 0 or handle error as needed
	}
	return a / b;
}

int main() {
	bool running = true;

	while (running) {
		double num1, num2;
		char op;


		std::cout << "Enter calculation (e.g. 5 + 3), or 'q' to quit: ";

		// Check if the user wants to quit before trying to read numbers
		std::string firstInput;
		std::cin >> firstInput;

		if (firstInput == "q") {
			running = false;
			continue; // skips the rest of this loop iteration, goes back to the while check
		}
		// Convert the first input (read as a string) into a number
		num1 = std::stod(firstInput); // stod = "string to double"

		std::cin >> op;
		std::cin >> num2;

		double result = 0;

		if (op == '+') {
			result = add(num1, num2);
		}
		else if (op == '-') {
			result = subtract(num1, num2);
		}
		else if (op == '*') {
			result = multiply(num1, num2);
		}
		else if (op == '/') {
			result = divide(num1, num2);
		}
		else {
			std::cout << "Unknown operator: " << op << std::endl;
			continue;
		}

		std::cout << "Result: " << result << std::endl << std::endl;
	}

	std::cout << "Goodbye!" << std::endl;
	return 0;
}