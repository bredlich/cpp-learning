#include <iostream>
#include <fstream> // Needed for file I/O
#include <string>

int main() {
    std::ofstream outFile("patients.csv"); // Output file

    if (!outFile.is_open()) {
        std::cout << "Failed to open file for writing." << std::endl;
        return 1;
    }

    // Write a header row, then some data rows, matching the format of the CSV file
    outFile << "ID,Name,Age\n";
    outFile << "101, Harry Smith, 22\n";
    outFile << "102, Fern Holt, 39\n";
    outFile << "103, Alex Hewitt, 27\n";

    outFile.close(); // Always close when done writing

    return 0;
}
