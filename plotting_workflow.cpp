#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

const double PI = 3.14159265358979323846;

int main() {
    std::ofstream outFile("sine_wave.csv");

    if (!outFile.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return 1;
    }

    outFile << "x,y\n"; // header row

    int numPoints = 100;
    for (int i = 0; i < numPoints; i++) {
        double x = i * (2 * PI / numPoints); // spread points across 0 to 2pi
        double y = std::sin(x);
        outFile << x << "," << y << "\n";
    }

    outFile.close();
    std::cout << "Wrote sine_wave.csv with " << numPoints << " points." << std::endl;

    return 0;
}
