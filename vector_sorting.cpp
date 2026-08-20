#include <iostream>
#include <vector>
#include <algorithm> // needed for sort, find

int main() {
    std::vector<int> numbers = { 42, 17, 8, 99, 23, 4 };

    std::cout << "Before sorting: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::sort(numbers.begin(), numbers.end());

    std::cout << "After sorting: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Sorting in descending order
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    std::cout << "Descending: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
