#include <iostream>

// A struct, just grouping data, no need for encapsulation here
struct Point {
    double x;
    double y;
};

// The same thing as a class, for comparison notice the "public:" is required here
class PointAsClass {
public:
    double x;
    double y;
};

int main() {
    // Struct members are public by default, so this works with no "public:" needed
    Point p1;
    p1.x = 3.0;
    p1.y = 4.0;
    std::cout << "Struct point: (" << p1.x << ", " << p1.y << ")" << std::endl;

    // Class version, identical behaviour, just needed "public:" explicitly
    PointAsClass p2;
    p2.x = 5.0;
    p2.y = 6.0;
    std::cout << "Class point: (" << p2.x << ", " << p2.y << ")" << std::endl;

    return 0;
}
