//
//  romaToInt.hpp
//  Leetcode
//
//  Created by dsh on 2021/7/11.
//

#ifndef romaToInt_hpp
#define romaToInt_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {

public:
    Solution(){};
    int RomanToInt(const std::string& s); 

private:
    std::unordered_map<char, int> roma_ = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
};
 
#endif /* romaToInt_hpp */
