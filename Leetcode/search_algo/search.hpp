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
void PermutationDfs(int depth, std::vector<int>& subResult,
                    std::vector<std::vector<int>>& result,
                    std::vector<int>& used,
                    const int length,
                    const std::vector<int>& nums);

#endif /* SEARCH_ALGO_SEARCH_HPP */
