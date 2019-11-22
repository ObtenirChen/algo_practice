//
//  AllSort.cpp
//  Algo_Practice
//
//  Created by Obtenir Chen on 2019/11/22.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include "ListNode.cpp"
#include <vector>

using namespace std;

class AllSort {
    
public:
    
    void quickSortList(ListNode *left, ListNode *right) {
        if (left == right || left == NULL || right == NULL) {
            return;
        }
        ListNode *p = left;
        ListNode *cur = left;
        ListNode *pre = NULL;
        int val = right->val;
        
        while (p != right) {
            if (p->val < val) {
                int temp = p->val;
                p->val = cur->val;
                cur->val = temp;
                pre = cur;
                cur = cur->next;
            }
            p = p->next;
        }
        if (cur != right) {
            int temp = right->val;
            right->val = cur->val;
            cur->val = temp;
            cur = cur->next;
        }
        
        quickSortList(left, pre);
        quickSortList(cur, right);
    }
    
    void mergeSort(vector<int> &arr, int low, int high) {
        
    }
    
};
