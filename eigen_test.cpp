#include <iostream>
#include <Eigen/Dense>

int main() {
    // A 3x3 matrix, using Eigen's Matrix type instead of vector<vector<double>>
    Eigen::Matrix3d matrix;
    matrix << 1, 2, 3,
        4, 5, 6,
        7, 8, 10;

    Eigen::Vector3d vec(1, 2, 3);

    // Matrix-vector multiply
    Eigen::Vector3d result = matrix * vec;

    std::cout << "Matrix:\n" << matrix << std::endl;
    std::cout << "Vector:\n" << vec << std::endl;
    std::cout << "Result:\n" << result << std::endl;

    // Matrix inverse, not easy to do by hand without eigen
    Eigen::Matrix3d inverse = matrix.inverse();
    std::cout << "Inverse:\n" << inverse << std::endl;

    return 0;
}
