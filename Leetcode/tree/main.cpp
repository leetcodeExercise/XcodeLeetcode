//
//  main.cpp
//  tree
//
//  Created by dsh on 2021/7/21.
//

#include <iostream>

#include "binary_tree.hpp"

int main() {
    TreeNode tree;
    BTreeOrderType orderType = BTreeOrderType::PreOrder;
    BTree bTree;
    
    std::cout << "PLS input the tree InOrderTraversal" << std::endl;
    bTree.CreatBTree(&tree);
    std::cout << "debug 1 " << std::endl;
    std::vector<int> result = bTree.Traversal(orderType, &tree);
    
    std::cout << "result is: " << std::endl;
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
