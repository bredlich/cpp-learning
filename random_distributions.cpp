#include <iostream>
#include <random>

int main() {
    // A random engine, the actual source of randomness, seeded once
    std::random_device rd; // Gets a random seed from the operating system
    std::mt19937 gen(rd()); // mt19937 = "Mersenne Twister" - a high quality standard generator

    // Distribution 1: uniform integers betweeen 1 and 6 (like a dice roll)
    std::uniform_int_distribution<int> dice(1, 6);

    std::cout << "Rolling a dice 5 times: ";
    for (int i = 0; i < 5; i++) {
        std::cout << dice(gen) << " ";
    }
    std::cout << std::endl;

    // Distribution 2: uniform real numbers between 0.0 and 1.0
    std::uniform_real_distribution<double> uniform(0.0, 1.0);

    std::cout << "5 uniform doubles: ";
    for (int i = 0; i < 5; i++) {
        std::cout << uniform(gen) << " ";
    }
    std::cout << std::endl;

    // Distribution 3: normal (Gaussian) distribution, mean 0, standar deviation 1
    std::normal_distribution<double> gaussian(0.0, 1.0);

    std::cout << "5 Gaussian samples: ";
    for (int i = 0; i < 5; i++) {
        std::cout << gaussian(gen) << " ";
    }
    std::cout << std::endl;

    return 0;
}
