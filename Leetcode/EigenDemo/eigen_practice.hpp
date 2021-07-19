//
//  eigenPractice.hpp
//  EigenDemo
//
//  Created by dsh on 2021/7/18.
//

#ifndef EIGENDEMO_EIGEN_PRACTICE_H_
#define EIGENDEMO_EIGEN_PRACTICE_H_

#include <iostream>
#include <stdio.h>

#include "Eigen/Eigen"

constexpr int MATRIX_SIZE = 50;

class EigenPractice {
  public:
    EigenPractice() {};
    void EigenBasic();
    void EigenGeometry();
};

#endif  // EIGENDEMO_EIGEN_PRACTICE_H_
