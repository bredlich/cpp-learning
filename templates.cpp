#include <iostream>
#include <string>

// Without templates, you need a seperate function for each type
int maxInt(int a, int b) {
    return (a > b) ? a : b;
}

double maxDouble(double a, double b) {
    return (a > b) ? a : b;
}

// With a template, on function can handle any type that supports the '>' operator
template<typename T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "maxInt: " << maxInt(3, 7) << std::endl;
    std::cout << "maxDouble: " << maxDouble(2.5, 1.8) << std::endl;

    // maxOf works for int, double even string, the compiler generates a seperate vision behind the scenes for whichever type you use
    std::cout << "maxOf (int): " << maxOf(3, 7) << std::endl;
    std::cout << "maxOf (double): " << maxOf(2.5, 1.8) << std::endl;
    std::cout << "maxOf (string): " << maxOf(std::string("apple"), std::string("banana")) << std::endl;

    return 0;
}
