#include "src/Matrix.hpp"

int main() {
    Matrix<int> A{{12,  43},
                  {-22, 10}};

    Matrix<int> B{{1, 0},
                  {0, 1}};

    auto C = detail::StrassenMultiplication(A, B, MatrixMultiplicationPolicy::StrassenParallel, SIZE_BOUND);

    C.print(std::cout);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
