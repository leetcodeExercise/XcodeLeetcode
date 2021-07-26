//
//  binary_tree.hpp
//  tree
//
//  Created by dsh on 2021/7/21.
//

#ifndef TREE_BINARY_TREE_HPP
#define TREE_BINARY_TREE_HPP

#include <vector>

struct TreeNode {
  public:
    explicit TreeNode() { }
    ~TreeNode() {
        if (left) {
            left->~TreeNode();
            free(left);
            std::cout << "free left node" << std::endl;
        }
        if (right) {
            right->~TreeNode();
            free(right);
            std::cout << "free right node" << std::endl;
        }
        std::cout << "~TreeNode() succeed" << std::endl;
    }
    int data;
    TreeNode* right = nullptr;
    TreeNode* left = nullptr;
};

enum class BTreeOrderType {
    PreOrder = 0,
    InOrder = 1,
    PostOrder = 2,
};

class BTree {
  public:
    explicit BTree(const std::vector<int>& level_order) {
        _root = CreatSubTree(level_order, 0);
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
    std::vector<int> Traversal(BTreeOrderType order_type);
    std::vector<std::vector<int>> LevelTraversal();
    
  private:
    TreeNode* CreatSubTree(const std::vector<int>& level_order, int iterator);
    void PreOrderTraversal(TreeNode* node, std::vector<int>& result);
    void InOrderTraversal(TreeNode* node, std::vector<int>& result);
    void PostOrderTraversal(TreeNode* node, std::vector<int>& result);
    void InnerLevelTraversal(TreeNode* node, std::vector<std::vector<int>>& result,
                             int depth);
    
    TreeNode* _root = nullptr;
};

#endif  // TREE_BINARY_TREE_HPP
