//
//  main.cpp
//  tree
//
//  Created by dsh on 2021/7/21.
//

#include <iostream>

#include "binary_tree.hpp"

int main() {
    TreeNode* tree = new TreeNode;
    BTreeOrderType orderType = BTreeOrderType::PreOrder;
    BTree bTree;
    //      1
    //     / \
    //    2   3
    //   / \ / \
    //  4  5 6 7
    // / \ /
    //8  9 0
    std::vector<int> level_order = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    tree = bTree.CreatBTree(level_order, tree, 0);
    std::vector<int> result = bTree.Traversal(orderType, tree);
    
    std::cout << "result is: " << std::endl;
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
