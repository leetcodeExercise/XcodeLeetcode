//
//  main.cpp
//  mereTwoLiat
//
//  Created by dsh on 2021/7/11.
//

#include <iostream>
#include <vector>

#include "mergeTwoLists.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::vector<int> l1Init = {1, 2, 0};
    std::vector<int> l2Init = {2, 4, 7, 8};
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    std::cout << "l1: ";
    for (int i =0; i < l1Init.size(); i++) {
        l1 = new ListNode(l1Init[i], l1);
        std::cout << l1->val << ", ";
    }
    
    std::cout << "\nl2: ";
    for (int i =0; i < l2Init.size(); i++) {
        l2 = new ListNode(l2Init[i], l2);
        std::cout << l2->val << ", ";
    }
    
    Solution merge;
    ListNode* result = merge.mergeTwoList(l1, l2);
    
    std::cout << "\nmerge: ";
    while (result != nullptr) {
        std::cout << result->val << ", ";
        result = result->next;
    }
   
    return 0;
}
