#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = { 42, 17, 8, 99, 23, 4 };
    std::sort(numbers.begin(), numbers.end());

    // std::find, works on any vector, sorted or not, checks every element
    auto it = std::find(numbers.begin(), numbers.end(), 23);

    if (it != numbers.end()) {
        std::cout << "Found 23 at position: " << (it - numbers.begin()) << std::endl;
    }
    else {
        std::cout << "23 not found." << std::endl;
    }

    // An iterator explicitly, what "it" actually is above
    std::vector<int>::iterator start = numbers.begin();
    std::vector<int>::iterator end = numbers.end();

    std::cout << "Using an iterator directly: ";
    for (std::vector<int>::iterator i = start; i != end; ++i) {
        std::cout << *i << " "; // note: dereferencing, same idea as pointers from Part 7
    }
    std::cout << std::endl;

    return 0;
}
