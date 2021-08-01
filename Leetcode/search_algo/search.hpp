//
//  search.hpp
//  search_algo
//
//  Created by dsh on 2021/7/30.
//

#ifndef SEARCH_ALGO_SEARCH_HPP
#define SEARCH_ALGO_SEARCH_HPP

#include <vector>

std::vector<std::vector<int>> Permutation(const std::vector<int>& nums);
void PermutationDfs(int depth, const std::vector<int>& nums,
                    const int length,
                    std::vector<int>& used,
                    std::vector<int>& subResult,
                    std::vector<std::vector<int>>& result);

#endif /* SEARCH_ALGO_SEARCH_HPP */
