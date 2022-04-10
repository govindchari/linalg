#include "Matrix.hpp"
#include <iostream>

int main(){
    linalg::Matrix<float, 2, 3> m;
    std::cout << m.rows() << std::endl;
    std::cout << m.cols() << std::endl;
    std::cout << m(0,0) << std::endl;
}