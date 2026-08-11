#include <iostream>

int main() {
	// Request a single int's worth of memory from the heap
	int* heapNumber = new int;

	// No name for this memory, only heapNumber (pointer) can access it
	*heapNumber = 42;
	std::cout << "Value on the heap: " << *heapNumber << std::endl;

	// Must manually free it when done, the heap does not automatically clean up
	delete heapNumber;

	// heapNumber still holds the old address, but that memory is no longer valid,
	// using heapNumber now would be undefined behavior (using freed memory)
	heapNumber = nullptr; // Good practice, clear the pointer

	// Heap memory for an array, where the size isn't know until runtime
	int size; 
	std::cout << "How many numbers do you want to store? ";
	std::cin >> size;

	int* numbers = new int[size]; // Size only known now at runtime

	for (int i = 0; i < size; i++) {
		numbers[i] = i * 10;
	}

	std::cout << "Values: ";
	for (int i = 0; i < size; i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	delete[] numbers; // note [] needed when deleting an array

	return 0;
}