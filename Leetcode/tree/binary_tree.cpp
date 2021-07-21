//
//  binary_tree.cpp
//  tree
//
//  Created by dsh on 2021/7/21.
//

#include <vector>
#include <iostream>

#include "binary_tree.hpp"

void BTree::CreatBTree(TreeNode* tree) {
    int data;
    std::cin >> data;
    if (data == '-1') return;
    else {
        if (data == -2)
            tree = nullptr;
        else {
            std::cout << "debug 2" << std::endl;
            tree = new TreeNode;
            tree->data = data;
            CreatBTree(tree->left);
            CreatBTree(tree->right);
        }
    }
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

void BTree::PreOrderTraversal(TreeNode* root, std::vector<int>& temp) {
    if (!root) return;
    temp.push_back(root->data);
    PreOrderTraversal(root->left, temp);
    PreOrderTraversal(root->right, temp);
}

void BTree::InOrderTraversal(TreeNode* root, std::vector<int>& temp) {
    if (!root) return;
    InOrderTraversal(root->left, temp);
    temp.push_back(root->data);
    InOrderTraversal(root->right, temp);
}

void BTree::PostOrderTraversal(TreeNode* root, std::vector<int>& temp) {
    if (!root) return;
    PostOrderTraversal(root->left, temp);
    PostOrderTraversal(root->right, temp);
    temp.push_back(root->data);
}

// TODO: finish level traversal
void BTree::LevelTraversal(TreeNode* root, std::vector<int>& temp) {
    if (!root) return;
    temp.push_back(root->data);
    PostOrderTraversal(root->left, temp);
    PostOrderTraversal(root->right, temp);
}
