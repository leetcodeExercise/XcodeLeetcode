//
//  binaryTree.hpp
//  Leetcode
//
//  Created by dsh on 2021/7/11.
//

#ifndef binaryTree_hpp
#define binaryTree_hpp

#include <stdio.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
 };
 
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {

    }
};

#endif /* binaryTree_hpp */
