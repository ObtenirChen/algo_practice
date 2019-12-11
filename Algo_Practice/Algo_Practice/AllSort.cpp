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
        if (low >= high) {
            return;
        }
        
        int mid = (high - low)/2 + low;
        
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeArr(arr, low, mid, high);
    }
    
    void mergeArr(vector<int> &arr, int low, int mid, int high) {
        
        vector<int> temp(high - low + 1);
        
        int p1 = low;
        int p2 = mid + 1;
        int i = 0;
        
        while (p1 <= mid && p2 <= high) {
            if (arr[p1] < arr[p2]) {
                temp[i++] = arr[p1++];
            } else {
                temp[i++] = arr[p2++];
            }
        }
        
        while (p1 <= mid) {
            temp[i++] = arr[p1++];
        }
        
        while (p2 <= high) {
            temp[i++] = arr[p2++];
        }
        
        for (int i = 0; i < temp.size(); i++) {
            arr[low+i] = temp[i];
        }
    }
    
    
    void quickSort(vector<int> &arr, int lo, int hi) {
        
        if (lo >= hi) {
            return;
        }
        
        int i = lo;
        int j = hi;
        int temp = arr[lo];
        while (i < j) {
            while (i < j && arr[j] >= temp) {
                j--;
            }
            while (i < j && arr[i] <= temp) {
                i++;
            }
            int tt = arr[i];
            arr[i] = arr[j];
            arr[j] = tt;
        }
        int tt = arr[i];
        arr[i] = temp;
        arr[lo] = tt;
        quickSort(arr, lo, i-1);
        quickSort(arr, i+1, hi);
    }
    
};
