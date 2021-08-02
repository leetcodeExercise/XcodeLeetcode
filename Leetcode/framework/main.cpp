//
//  main.cpp
//  framework
//
//  Created by dsh on 2021/8/2.
//

#include <iostream>

#include "template.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Planner1Variable v1;
    Planner1Result r1(v1);
    Planner2Variable v2;
    Planner2Result r2(v2);
    return 0;
}
