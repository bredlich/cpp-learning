#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile("patients.csv"); // Input file

    if (!inFile.is_open()) {
        std::cout << "Failed to open file for reading." << std::endl;
        return 1;
    }

    std::string line;
    int lineNumber = 0;

    // getline reads one line at a time until the file runs out
    while (std::getline(inFile, line)) {
        if (lineNumber == 0) {
            std::cout << "Header: " << line << std::endl;
        }
        else {
            std::cout << " Row " << lineNumber << ": " << line << std::endl;
        }
        lineNumber++;
    }

    inFile.close();

    return 0;
}
