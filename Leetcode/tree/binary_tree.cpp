//
//  binary_tree.cpp
//  tree
//
//  Created by dsh on 2021/7/21.
//

#include <iostream>
#include <vector>

#include "binary_tree.hpp"

// TODO: what about incomplete binary tree?
TreeNode* BTree::CreatSubTree(const std::vector<int>& level_order, int iterator) {
    if (iterator < level_order.size()) {
        TreeNode* tree = new TreeNode();
        tree->data = level_order[iterator];
        tree->left = CreatSubTree(level_order, 2 * iterator + 1);
        tree->right = CreatSubTree(level_order, 2 * iterator + 2);
        return tree;
    } else {
        return nullptr;
    }
    
}

std::vector<int> BTree::Traversal(BTreeOrderType order_type) {
    std::vector<int> result;
    
    switch (order_type) {
        case BTreeOrderType::PreOrder:
            PreOrderTraversal(_root, result);
            break;
        case BTreeOrderType::InOrder:
            InOrderTraversal(_root, result);
            break;
        case BTreeOrderType::PostOrder:
            PostOrderTraversal(_root, result);
            break;
    }
    return result;
}

std::vector<std::vector<int>> BTree::LevelTraversal() {
    std::vector<std::vector<int>> result;
    InnerLevelTraversal(_root, result, 0);
    return result;
}
void BTree::PreOrderTraversal(TreeNode* root, std::vector<int>& result) {
    if (!root) return;
    result.push_back(root->data);
    PreOrderTraversal(root->left, result);
    PreOrderTraversal(root->right, result);
}

void BTree::InOrderTraversal(TreeNode* root, std::vector<int>& result) {
    if (!root) return;
    InOrderTraversal(root->left, result);
    result.push_back(root->data);
    InOrderTraversal(root->right, result);
}

void BTree::PostOrderTraversal(TreeNode* root, std::vector<int>& result) {
    if (!root) return;
    PostOrderTraversal(root->left, result);
    PostOrderTraversal(root->right, result);
    result.push_back(root->data);
}

void BTree::InnerLevelTraversal(TreeNode* root, std::vector<std::vector<int>>& result,
                                int depth) {
    if (!root) return;
    while (result.size() <= depth) {
        result.push_back({});
    }
    result[depth].push_back(root->data);
    InnerLevelTraversal(root->left, result, depth + 1);
    InnerLevelTraversal(root->right, result, depth + 1);
}
