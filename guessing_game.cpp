#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>   // for seeding rand() with the current time

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed randomness
	int secretNumber = std::rand() % 100 + 1; // Random number between 1 and 100

	int guess = 0;
	int attempts = 0;

	std::cout << "I'm thinking of a number between 1 and 100. " << std::endl;

	while (guess != secretNumber) {
		std::cout << "Enter your guess: ";
		std::cin >> guess;
		attempts++;

		if (guess < secretNumber) {
			std::cout << "Too low! Try again." << std::endl;
			}
		else if (guess > secretNumber) {
			std::cout << "Too high! Try again." << std::endl;
		}
	}

	std::cout << "Correct! You got it in " << attempts << " attempts." << std::endl;

	return 0;
}