//
//  main.cpp
//  EigenDemo
//
//  Created by dsh on 2021/7/16.
//

#include <iostream>

#include "Eigen/core"
#include "Eigen/Dense"

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;
    
    return 0;
}
