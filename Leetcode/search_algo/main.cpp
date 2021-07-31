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
    std::cout << "result is: " << std::endl;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}


