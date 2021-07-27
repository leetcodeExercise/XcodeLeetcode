//
//  binary_tree.hpp
//  tree
//
//  Created by dsh on 2021/7/21.
//

#ifndef TREE_BINARY_TREE_HPP
#define TREE_BINARY_TREE_HPP

#include <iostream>
#include <vector>

struct TreeNode {
  public:
    explicit TreeNode() {}
    ~TreeNode();
    int data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

enum class BTreeOrderType {
    PreOrder = 0,
    InOrder = 1,
    PostOrder = 2,
};

class BTree {
  public:
    explicit BTree(const std::vector<int>& levelOrder) {
        _root = CreatSubTree(levelOrder, 0);
    }
    ~BTree() {
        if (_root) {
            _root->~TreeNode();
            free(_root);
        }
    }
    TreeNode* root() const {
        return _root;
    }
    std::vector<int> Traversal(BTreeOrderType orderType);
    std::vector<std::vector<int>> LevelTraversal();
    
  private:
    TreeNode* CreatSubTree(const std::vector<int>& levelOrder, int iterator);
    void PreOrderTraversal(TreeNode* node, std::vector<int>& result);
    void InOrderTraversal(TreeNode* node, std::vector<int>& result);
    void PostOrderTraversal(TreeNode* node, std::vector<int>& result);
    void InnerLevelTraversal(TreeNode* node, std::vector<std::vector<int>>& result,
                             int depth);
    
    TreeNode* _root = nullptr;
};

#endif  // TREE_BINARY_TREE_HPP
