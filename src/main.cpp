#include "matrix.hpp"
#include <iostream>

int main(){
    linalg::Matrix<float, 2, 3> m = {1,2,3,4,5,6};
    
    std::cout << m.rows() << std::endl;
    std::cout << m.cols() << std::endl;
    std::cout << m(0,0) << std::endl;
    std::cout << m(0,1) << std::endl;
    std::cout << m(0,2) << std::endl;
    std::cout << m(1,0) << std::endl;
    std::cout << m(1,1) << std::endl;
    std::cout << m(1,2) << std::endl;
}