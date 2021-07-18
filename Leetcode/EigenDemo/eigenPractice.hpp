//
//  eigenPractice.hpp
//  EigenDemo
//
//  Created by dsh on 2021/7/18.
//

#ifndef eigenPractice_hpp
#define eigenPractice_hpp

#include <stdio.h>
#include <iostream>

#include "Eigen/core"
#include "Eigen/Dense"

using namespace Eigen;

#define MATRIX_SIZE 50

class eigenPractice {
public:
    eigenPractice() {};
    void eigenBasic();
    void eigenGeometry();
};

#endif /* eigenPractice_hpp */
