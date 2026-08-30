#include <iostream>
#include <vector>

// Dot product: multiply corresponding elements, sum the results
double dotProduct(const std::vector<double>& a, const std::vector<double>& b) {
    double result = 0.0;
    for (int i = 0; i < a.size(); i++) {
        result += a[i] * b[i];
    }
    return result;
}

// Matrix-vector multiply: a matrix here is a vector of vectors (rows)
std::vector<double> matrixVectorMultiply(const std::vector<std::vector<double>>& matrix,
    const std::vector<double>& vec) {
    std::vector<double> result;

    for (int row = 0; row < matrix.size(); row++) {
        result.push_back(dotProduct(matrix[row], vec)); // each output element is a dot product
    }

    return result;
}

int main() {
    std::vector<double> a = { 1, 2, 3 };
    std::vector<double> b = { 4, 5, 6 };

    std::cout << "Dot product of a and b: " << dotProduct(a, b) << std::endl;

    // A 2x3 matrix (2 rows, 3 columns)
    std::vector<std::vector<double>> matrix = {
        { 1, 0, 2 },
        { 0, 1, 1 }
    };

    std::vector<double> vec = { 3, 4, 5 };

    std::vector<double> result = matrixVectorMultiply(matrix, vec);

    std::cout << "Matrix-vector multiply result: ";
    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
