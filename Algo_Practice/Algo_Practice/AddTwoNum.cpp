//
//  AddTwoNum.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/5.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include "ListNode.cpp"

class AddTwoNum {
    
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;
        int add = 0;
        int b = 0;
        while (l1 != NULL && l2 != NULL) {
            int a = l1->val + l2->val + add;
            b = a % 10;
            add = a / 10;
            ListNode *temp = new ListNode(b);
            ptr->next = temp;
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL) {
            int a = l1->val + add;
            b = a % 10;
            add = a / 10;
            ListNode *temp = new ListNode(b);
            ptr->next = temp;
            ptr = ptr->next;
            l1 = l1->next;
        }
        
        while (l2 != NULL) {
            int a = l2->val + add;
            b = a % 10;
            add = a / 10;
            ListNode *temp = new ListNode(b);
            ptr->next = temp;
            ptr = ptr->next;
            l2 = l2->next;
        }
        
        if (add != 0) {
            ListNode *temp = new ListNode(add);
            ptr->next = temp;
            ptr = ptr->next;
        }
        
        return head->next;
    }
    
};
