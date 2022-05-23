#pragma once
#include <stdio.h>
#include <initializer_list>
#include <iostream>

namespace linalg
{
    template <typename T, size_t R, size_t C>
    class Matrix
    {
        static_assert(!(R == 0 || C == 0), "Dimension cannot be zero");

    private:
        static constexpr size_t num_rows = R;
        static constexpr size_t num_cols = C;
        T data[R * C] = {};

    public:
        Matrix(std::initializer_list<T> l)
        {
            int count = 0;
            for (auto i : l)
            {
                data[count] = i;
                ++count;
            }
        };
        Matrix() = default;
        size_t rows()
        {
            return num_rows;
        }
        size_t cols()
        {
            return num_cols;
        }
        T operator()(const int i, const int j)
        {
            static_assert(!(R == 1 || C == 1), "Invalid element access for a vector");
            return data[i * cols() + j];
        }
        T operator()(int i)
        {
            static_assert((R == 1 || C == 1), "Invalid element access for a matrix");
            return data[i];
        }
        void operator=(T rhs[R * C])
        {
            this->data = rhs;
        }
        Matrix<T, R, C> operator+(const Matrix<T, R, C> &M2)
        {
            Matrix<T, R, C> result;
            for (int i = 0; i < R * C; i++)
            {
                result.data[i] = this->data[i] + M2.data[i];
            }
            return result;
        }
        Matrix<T, R, C> operator-(const Matrix<T, R, C> &M2)
        {
            Matrix<T, R, C> result;
            for (int i = 0; i < R * C; i++)
            {
                result.data[i] = this->data[i] - M2.data[i];
            }
            return result;
        }
        std::ostream &operator<<(std::ostream &os, const Matrix<T, R, C> &m)
        {
            os << m(0, 0);
            return os;
        }
    };

    // Matrix typedefs and aliases
    template <size_t R, size_t C>
    using Matrixf = Matrix<float, R, C>;
    typedef Matrixf<2, 2> Matrix2x2f;
    typedef Matrixf<3, 3> Matrix3x3f;
    typedef Matrixf<2, 3> Matrix2x3f;
    typedef Matrixf<3, 2> Matrix3x2f;

    template <size_t R, size_t C>
    using Matrixd = Matrix<double, R, C>;
    typedef Matrixd<2, 2> Matrix2x2d;
    typedef Matrixd<3, 3> Matrix3x3d;
    typedef Matrixd<2, 3> Matrix2x3d;
    typedef Matrixd<3, 2> Matrix3x2d;

    // Vector typedefs and aliases
    template <size_t R>
    using Vectorf = Matrix<float, R, 1>;
    typedef Vectorf<2> Vector2f;
    typedef Vectorf<3> Vector3f;
    typedef Vectorf<4> Vector4f;

    template <size_t R>
    using Vectord = Matrix<double, R, 1>;
    typedef Vectord<2> Vector2d;
    typedef Vectord<3> Vector3d;
    typedef Vectord<4> Vector4d;
}
