//
// Created by Acer on 16.05.2021.
//

#ifndef LAB3A_MATRIX_H
#define LAB3A_MATRIX_H

#include <iostream>

template<typename T>
class Matrix;

enum class MatrixMultiplicationPolicy {
    Default, Strassen, StrassenParallel
};

namespace detail {
    template<typename TT>
    Matrix<TT> defaultMultiplication(const Matrix<TT> &lhs, const Matrix<TT> &rhs);

    template<typename TT>
    Matrix<TT> StrassenMultiplication(const Matrix<TT> &lhs,
                                      const Matrix<TT> &rhs,
                                      MatrixMultiplicationPolicy policy,
                                      const std::size_t &size_bound
    );

    template<typename TT>
    Matrix<TT> StrassenMultiplicationStep(const Matrix<TT> &lhs,
                                          const Matrix<TT> &rhs,
                                          const std::size_t &size,
                                          const std::size_t &size_bound
    );

    template<typename TT>
    Matrix<TT> StrassenMultiplicationStepParallel(const Matrix<TT> &lhs,
                                                  const Matrix<TT> &rhs,
                                                  const std::size_t &size,
                                                  const std::size_t &size_bound
    );
}

#endif //LAB3A_MATRIX_H
