#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // for min/max
#include <numeric> // for accumulate

int main() {
    std::ifstream inFile("scores.csv");

    if (!inFile.is_open()) {
        std::cout << "Failed to open scores.csv" << std::endl;
        return 1;
    }

    std::vector<double> scores;
    std::string line;

    while (std::getline(inFile, line)) {
        if (!line.empty()) {
            scores.push_back(std::stod(line)); // string to double
        }
    }
    inFile.close();

    if (scores.empty()) {
        std::cout << "No data found." << std::endl;
        return 1;
    }

    // Summary Statistics
    int count = scores.size();
    double sum = std::accumulate(scores.begin(), scores.end(), 0.0);
    double mean = sum / count;
    double minVal = *std::min_element(scores.begin(), scores.end());
    double maxVal = *std::max_element(scores.begin(), scores.end());

    std::cout << "Scores Report" << std::endl;
    std::cout << "-------------" << std::endl;
    std::cout << "Count: " << count << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Min: " << minVal << std::endl;
    std::cout << "Max: " << maxVal << std::endl;

    return 0;

}
