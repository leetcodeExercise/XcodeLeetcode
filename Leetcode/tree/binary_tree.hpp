//
//  binary_tree.hpp
//  tree
//
//  Created by dsh on 2021/7/21.
//

#ifndef TREE_BINARY_TREE
#define TREE_BINARY_TREE

#include <vector>
#include <stack>

class TreeNode {
  public:
    int data;
    TreeNode *right;
    TreeNode *left;
};

enum class BTreeOrderType {
    PreOrder = 0,
    InOrder = 1,
    PostOrder = 2,
    Level = 3,
};

class BTree {
  public:
    BTree() = default;
    void CreatBTree(TreeNode* tree);
    std::vector<int> Traversal(BTreeOrderType orderType, TreeNode* root);
        
  private:
    void PreOrderTraversal(TreeNode* root, std::vector<int>& temp);
    void InOrderTraversal(TreeNode* root, std::vector<int>& temp);
    void PostOrderTraversal(TreeNode* root, std::vector<int>& temp);
    void LevelTraversal(TreeNode*root, std::vector<int>& temp);
};

#endif  // TREE_BINARY_TREE
