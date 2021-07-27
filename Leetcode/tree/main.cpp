//
//  main.cpp
//  tree
//
//  Created by dsh on 2021/7/21.
//

#include <iostream>

#include "binary_tree.hpp"

int main() {
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6 7
    //  / \ /
    // 8  9 0
    std::vector<int> levelOrder = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    BTree bTree = BTree(levelOrder);
    std::vector<int> result = bTree.Traversal(BTreeOrderType::PreOrder);
    
    std::cout << "result is: " << std::endl;
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    
    // level order traversal
    std::vector<std::vector<int>> levelTraversalResult;
    levelTraversalResult = bTree.LevelTraversal();
    std::cout << "level order traversal result is: " << std::endl;
    for (int i = 0; i < levelTraversalResult.size(); i++) {
        for (int j = 0; j < levelTraversalResult[i].size(); j++) {
            std::cout << levelTraversalResult[i][j] << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}
