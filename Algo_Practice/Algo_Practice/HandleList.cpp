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
    
    
    ListNode *revertList_0105(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        
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
    
    
    ListNode *revertList_010502(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *p = revertList_010502(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return p;
    }
    
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == nullptr) {
            return head;
        }
        
        // 移动节点
        ListNode *cur = head;
        ListNode *pre = nullptr;
        while (m > 1) {
            pre = cur;
            cur = cur->next;
            m--;
            n--;
        }
        
        ListNode *con = pre;
        ListNode *tail = cur;
        while (n > 0) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            n--;
        }
        
        if (con != nullptr) {
            con->next = pre;
        } else {
            head = pre;
        }
        
        tail->next = cur;
        
        return head;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dumyHead = new ListNode(-1);
        ListNode *p = dumyHead;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        if (l1 != NULL) {
            p->next = l1;
        }
        if (l2 != NULL) {
            p->next = l2;
        }
        
        return dumyHead->next;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;
        int add = 0;
        int x = 0;
        while (l1 != nullptr || l2 != nullptr) {
            add = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + x;
            x = add / 10;
            add = add % 10;
            
            ListNode *temp = new ListNode(add);
            ptr->next = temp;
            temp->next = nullptr;
            ptr = ptr->next;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        
        if (x != 0) {
            ListNode *temp = new ListNode(x);
            ptr->next = temp;
            ptr = ptr->next;
        }
        
        return head->next;
        
        
    }
};
