//
//  mergeTwoLists.cpp
//  Leetcode
//
//  Created by dsh on 2021/7/11.
//

#include "mergeTwoLists.hpp"

ListNode* Solution::mergeTwoList(ListNode* l1, ListNode* l2) {
    if (!l1)
        return l2;
    else if (!l2)
        return l1;
    
    if (l1->val < l2->val) {
        l1->next = mergeTwoList(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoList(l1, l2->next);
        return l2;
    }
};
