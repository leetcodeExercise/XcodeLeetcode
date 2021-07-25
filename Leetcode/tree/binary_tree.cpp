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
TreeNode* BTree::CreatBTree(std::vector<int>& level_order,
                           TreeNode* tree_root, int iterator) {
    if (iterator < level_order.size()) {
        TreeNode* tree = new TreeNode;
        tree->left = nullptr;
        tree->right = nullptr;
        tree_root = tree;
        tree_root->data = level_order[iterator];
        tree_root->left = CreatBTree(level_order, tree_root->left, 2 * iterator + 1);
        tree_root->right = CreatBTree(level_order, tree_root->right, 2 * iterator + 2);
    }
    return tree_root;
}

std::vector<int> BTree::Traversal(BTreeOrderType orderType,
                                  TreeNode* root) {
    std::vector<int> result;
    
    switch (orderType) {
        case BTreeOrderType::PreOrder:
            PreOrderTraversal(root, result);
            break;
        case BTreeOrderType::InOrder:
            InOrderTraversal(root, result);
            break;
        case BTreeOrderType::PostOrder:
            PostOrderTraversal(root, result);
            break;
        case BTreeOrderType::Level:
            LevelTraversal(root, result);
            break;
    }
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

// TODO: complete the func
void BTree::LevelTraversal(TreeNode* root, std::vector<int>& result) {
    if (!root) return;
    result.push_back(root->data);
    PostOrderTraversal(root->left, result);
    PostOrderTraversal(root->right, result);
}
