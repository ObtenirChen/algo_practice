//
//  HandleList.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/11/24.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include "ListNode.cpp"

class HandleList {
    
public:
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        ListNode *ptr = head;
        int n = 0;
        while (ptr != NULL) {
            ptr = ptr->next;
            n++;
        }
        
        if (k % n == 0) {
            return head;
        }
        
        ListNode *kptr = head;
        int i = n - k % n;
        while (i-1 && kptr != NULL) {
            kptr = kptr->next;
            i--;
        }
        
        ListNode *tempPre = kptr;
        ListNode *tempH = kptr->next;
        ListNode *newHead = tempH;
        
        while (tempH->next != NULL) {
            tempH = tempH->next;
        }
        
        tempH->next = head;
        tempPre->next = NULL;
        
        return newHead;
    }
    
    
//    ListNode* reverseList(ListNode* head) {
//        ListNode *pre = NULL;
//        ListNode *cur = head;
//        ListNode *next = NULL;
//        while (cur != NULL) {
//            next = cur->next;
//            cur->next = pre;
//            pre = cur;
//            cur = next;
//        }
//        return pre;
//    }
//
//    ListNode* reverseList2(ListNode* head) {
//        if (head == NULL || head->next == NULL) {
//            return head;
//        }
//
//        ListNode *p = reverseList2(head->next);
//        head->next->next = head;
//        head->next = NULL;
//        return p;
//    }
    
    
    ListNode *revertList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    
    
    ListNode *revertList2(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *p = revertList2(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};
