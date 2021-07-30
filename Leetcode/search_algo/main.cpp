//
//  main.cpp
//  search_algo
//
//  Created by dsh on 2021/7/30.
//

#include <iostream>

#include "search.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result;
    result = Permutation(nums);
    return 0;
}


