//
//  binary_tree.hpp
//  tree
//
//  Created by dsh on 2021/7/21.
//

#ifndef TREE_BINARY_TREE
#define TREE_BINARY_TREE

#include <stack>
#include <vector>

class TreeNode {
  public:
    int data;
    TreeNode* right;
    TreeNode* left;
};

enum class BTreeOrderType {
    PreOrder = 0,
    InOrder = 1,
    PostOrder = 2,
};

class BTree {
  public:
    BTree() = default;
    TreeNode* CreatBTree(std::vector<int>& level_order,TreeNode* tree_root, int iterator);
    std::vector<int> Traversal(BTreeOrderType orderType, TreeNode* root);
    void PreOrderTraversal(TreeNode* root, std::vector<int>& result);
    void InOrderTraversal(TreeNode* root, std::vector<int>& result);
    void PostOrderTraversal(TreeNode* root, std::vector<int>& result);
    void LevelTraversal(TreeNode* root, std::vector<std::vector<int>>& result,
                        int depth);
};

#endif  // TREE_BINARY_TREE
