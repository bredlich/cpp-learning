#include <iostream>
#include <cmath>
#include <functional>

const double PI = 3.14159265358979323846;

// Trapezoidal rule: approximates the integral of f from a to b, using n intervals
double trapezoidalIntegrate(std::function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n; // width of each interval
    double sum = 0.5 * (f(a) + f(b)); // first and last points count half

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return sum * h;
}

int main() {
    // Example 1: integrate f(x) = x^2 from 0 to 1 (exact answer: 1/3 ≈ 0.3333)
    auto square = [](double x) { return x * x; };
    double result1 = trapezoidalIntegrate(square, 0.0, 1.0, 1000);
    std::cout << "Integral of x^2 from 0 to 1: " << result1 << std::endl;

    // Example 2: integrate sin(x) from 0 to pi (exact answer: 2)
    auto sinFunc = [](double x) { return std::sin(x); };
    double result2 = trapezoidalIntegrate(sinFunc, 0.0, PI, 1000);
    std::cout << "Integral of sin(x) from 0 to pi: " << result2 << std::endl;

    // Try with fewer intervals - notice the answer gets less accurate
    double resultCoarse = trapezoidalIntegrate(square, 0.0, 1.0, 10);
    std::cout << "Integral of x^2 with only 10 intervals: " << resultCoarse << std::endl;

    return 0;
}
