//
//  template.cpp
//  framework
//
//  Created by dsh on 2021/8/2.
//

#include <iostream>

#include "template.hpp"

Planner1Variable::~Planner1Variable() {
    if (_ptr) free(_ptr);
    std::cout << "~Planner1Variable succeed!" << std::endl;
}
