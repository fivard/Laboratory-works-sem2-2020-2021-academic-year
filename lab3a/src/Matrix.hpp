#pragma once

#include <type_traits>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <future>

template<typename T>
class Matrix;

enum class MatrixMultiplicationPolicy {
    Default, Strassen, StrassenParallel
};

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


template<typename T>
class Matrix {
    static_assert(std::is_arithmetic_v<T>);

public:
    Matrix(const std::size_t &rows, const std::size_t &cols, const T &default_element = 0);

    Matrix(std::initializer_list<std::vector<T>> elements);

    explicit Matrix(const std::vector<std::vector<T>> &elements);


    T operator()(const std::size_t &row, const std::size_t &col) const;

    T &operator()(const std::size_t &row, const std::size_t &col);

    [[nodiscard]] std::size_t size_rows() const;

    [[nodiscard]] std::size_t size_cols() const;

    template<typename OStream>
    void print(OStream &os);

    template<typename TT>
    friend Matrix<TT> StrassenMultiplication(const Matrix<TT> &lhs,
                                                     const Matrix<TT> &rhs,
                                                     MatrixMultiplicationPolicy policy,
                                                     const std::size_t &size_bound
    );

    template<typename TT>
    friend Matrix<TT> StrassenMultiplicationStep(const Matrix<TT> &lhs,
                                                         const Matrix<TT> &rhs,
                                                         const std::size_t &size,
                                                         const std::size_t &size_bound
    );

    template<typename TT>
    friend Matrix<TT> StrassenMultiplicationStepParallel(const Matrix<TT> &lhs,
                                                                 const Matrix<TT> &rhs,
                                                                 const std::size_t &size,
                                                                 const std::size_t &size_bound
    );


    ~Matrix();
private:
    std::vector<std::vector<T>> _rows;

};

template<typename T>
Matrix(std::initializer_list<std::vector<T>>) -> Matrix<T>;

template<typename T>
Matrix(const std::size_t &, const std::size_t &, const T &) -> Matrix<T>;


template<typename T>
Matrix<T> operator+(const Matrix<T> &lhs, const Matrix<T> &rhs);

template<typename T>
Matrix<T> operator-(const Matrix<T> &lhs, const Matrix<T> &rhs);

template<typename T>
bool operator==(const Matrix<T> &lhs, const Matrix<T> &rhs);

template<typename T>
bool operator!=(const Matrix<T> &lhs, const Matrix<T> &rhs);

template<typename T>
Matrix<T> multiply(const Matrix<T> &lhs,
                   const Matrix<T> &rhs);

constexpr std::size_t SIZE_BOUND = 64;

template<typename T>
Matrix<T> multiply(const Matrix<T> &lhs,
                   const Matrix<T> &rhs,
                   MatrixMultiplicationPolicy policy,
                   const std::size_t &size_bound = SIZE_BOUND
);

#include "Matrix.hxx"
