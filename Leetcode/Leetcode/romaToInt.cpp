//
//  romaToInt.cpp
//  Leetcode
//
//  Created by dsh on 2021/7/11.
//

#include "romaToInt.hpp"

#include "romaToInt.hpp"

int Solution::RomanToInt(const std::string& s){
    int x = 0;
    for (int i = 0; i < s.length(); i++) {
        int value = roma_[s[i]];
        (value < roma_[s[i + 1]]) && (i < s.length() - 1) ?
            x = x - value : x = x + value;
    }
    return x;
}
