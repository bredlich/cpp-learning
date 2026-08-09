#include <iostream>
#include <vector>
#include <string>

int main() {
	// Declaring and Intialising a vector 
	std::vector<int> scores = { 85, 92, 78, 90, 65 };

	// Looping over it ("range-based for loop")
	std::cout << "Scores: ";
	for (int score : scores) {
		std::cout << score << " ";
	}
	std::cout << std::endl;

	//Adding an item to the end
	scores.push_back(100);

	//Accessing by index (zero-based like most languages other than R)
	std::cout << "First score: " << scores[0] << std::endl;
	std::cout << "Number of scores: " << scores.size() << std::endl;

	// Strings - basic manipulation
	std::string firstName = "Ben";
	std::string lastName = "Smith";
	std::string fullName = firstName + " " + lastName; // concatenation with +

	std::cout << "Full name: " << fullName << std::endl;
	std::cout << "Name length: " << fullName.length() << std::endl;

	// cin - reading user input
	std::string userInput;
	std::cout << "What's your favourite number? ";
	std::cin >> userInput;
	std::cout << "You said: " << userInput << std::endl;

	return 0;

}