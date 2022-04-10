#pragma once
#include <vector>

namespace linalg
{
    template <typename T, size_t R, size_t C>
    class Matrix
    {
    private:
        size_t num_rows = R;
        size_t num_cols = C;
        T data[R*C] = {};

    public:
        Matrix(std::initializer_list<T> l)
        {
            int count = 0;
            for (auto i : l){
                data[count] = i;
                ++count;
            }
        };
        size_t rows()
        {
            return num_rows;
        }
        size_t cols()
        {
            return num_cols;
        }
        T operator()(int i, int j)
        {
            return data[i * cols() + j];
        }
        void operator=(T rhs[R*C]){
            data = rhs;
        }
    };
}
