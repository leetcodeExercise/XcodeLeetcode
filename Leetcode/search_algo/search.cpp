//
//  search.cpp
//  search_algo
//
//  Created by dsh on 2021/7/30.
//

#include <vector>

#include "search.hpp"

/* Input: a collection of distinct integers
   Output: all possible permutations
 
 Example:

 Input: [1, 2, 3]
 Output:
 [
   [1, 2, 3]
   [1, 3, 2]
   [2, 1, 3]
   [2, 3, 1]
   [3, 1, 2]
   [3, 2, 1]
 ] */
std::vector<std::vector<int>> Permutation(const std::vector<int>& nums) {
    int length = static_cast<int>(nums.size());
    std::vector<std::vector<int>> result;
    std::vector<int> subResult;
    std::vector<int> used(length);
    PermutationDfs(0, subResult, result, used, length, nums);
    return result;
}

void PermutationDfs(int depth, std::vector<int>& subResult,
                    std::vector<std::vector<int>>& result,
                    std::vector<int>& used,
                    const int length,
                    const std::vector<int>& nums) {
    if (depth == length) {
        result.push_back(subResult);
        return;
    }
    for (int i = 0; i < length; i++) {
        if (used[i]) continue;
        used[i] = 1;
        subResult.push_back(nums[i]);
        PermutationDfs(depth + 1, subResult, result, used, length, nums);
        subResult.pop_back();
        used[i] = 0;
    }
}
