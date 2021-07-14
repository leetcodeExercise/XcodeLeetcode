//
//  mergeTwoLists.hpp
//  Leetcode
//
//  Created by dsh on 2021/7/11.
//

#ifndef mergeTwoLists_hpp
#define mergeTwoLists_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    Solution() {};
    ListNode* mergeTwoList(ListNode* l1,ListNode* l2);
};
#endif /* mergeTwoLists_hpp */
