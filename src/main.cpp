#include "matrix.hpp"
#include <iostream>

int main(){
    linalg::Matrix2x2f m1 = {1,2,3,4};
    linalg::Matrix2x2f m2 = {2,4,6,8};

    m2 = m1;

    auto m3 = m1+m2;

    std::cout << m3.rows() << std::endl;
    std::cout << m3.cols() << std::endl;
    std::cout << m3(0,0) << std::endl;
    std::cout << m3(0,1) << std::endl;
    std::cout << m3(1,0) << std::endl;
    std::cout << m3(1,1) << std::endl;
}