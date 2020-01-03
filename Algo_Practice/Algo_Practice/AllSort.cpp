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
    
//    void mergeSort(vector<int> &arr, int low, int high) {
//        if (low >= high) {
//            return;
//        }
//
//        int mid = (high - low)/2 + low;
//
//        mergeSort(arr, low, mid);
//        mergeSort(arr, mid + 1, high);
//        mergeArr(arr, low, mid, high);
//    }
//
//    void mergeArr(vector<int> &arr, int low, int mid, int high) {
//
//        vector<int> temp(high - low + 1);
//
//        int p1 = low;
//        int p2 = mid + 1;
//        int i = 0;
//
//        while (p1 <= mid && p2 <= high) {
//            if (arr[p1] < arr[p2]) {
//                temp[i++] = arr[p1++];
//            } else {
//                temp[i++] = arr[p2++];
//            }
//        }
//
//        while (p1 <= mid) {
//            temp[i++] = arr[p1++];
//        }
//
//        while (p2 <= high) {
//            temp[i++] = arr[p2++];
//        }
//
//        for (int i = 0; i < temp.size(); i++) {
//            arr[low+i] = temp[i];
//        }
//    }
//
    
//    void quickSort(vector<int> &arr, int lo, int hi) {
//
//        if (lo >= hi) {
//            return;
//        }
//
//        int i = lo;
//        int j = hi;
//        int temp = arr[lo];
//        while (i < j) {
//            while (i < j && arr[j] >= temp) {
//                j--;
//            }
//            while (i < j && arr[i] <= temp) {
//                i++;
//            }
//            int tt = arr[i];
//            arr[i] = arr[j];
//            arr[j] = tt;
//        }
//        int tt = arr[i];
//        arr[i] = temp;
//        arr[lo] = tt;
//        quickSort(arr, lo, i-1);
//        quickSort(arr, i+1, hi);
//    }
    
    
    void quickSort(vector<int> &arr, int low, int hight) {
        
        if (low >= hight) {
            return;
        }
        
        int i = low;
        int j = hight;
        int temp = arr[low];
        
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
        arr[i] = arr[low];
        arr[low] = tt;
        
        quickSort(arr, low, i-1);
        quickSort(arr, i+1, hight);
    }
    
    void mergeSort(vector<int> &arr, int low, int hight) {
        if (low >= hight) {
            return;
        }
        int mid = low + (hight - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, hight);
        merge(arr, low, hight, mid);
    }
    
    
    void merge(vector<int> &arr, int low, int hight, int mid) {
        vector<int> temp(hight - low + 1);
        int p1 = low;
        int p2 = mid + 1;
        int i = 0;
        while (p1 <= mid && p2 <= hight) {
            if (arr[p1] < arr[p2]) {
                temp[i++] = arr[p1++];
            } else {
                temp[i++] = arr[p2++];
            }
        }
        
        while (p1 <= mid) {
            temp[i++] = arr[p1++];
        }
        
        while (p2 <= hight) {
            temp[i++] = arr[p2++];
        }
        
        for (int j = 0; j < temp.size(); j++) {
            arr[low + j] = temp[j];
        }
        
    }
    
    
    void quickSort_0103(vector<int> &arr, int left, int right) {
        if (left >= right) {
            return;
        }
        
        int lo = left;
        int hi = right;
        int temp = arr[lo];
        
        while (lo < hi) {
            while (lo < hi && arr[hi] >= temp) {
                hi--;
            }
            while (lo < hi && arr[lo] <= temp) {
                lo++;
            }
            int tt = arr[lo];
            arr[lo] = arr[hi];
            arr[hi] = tt;
        }
        int tt = arr[left];
        arr[left] = arr[right];
        arr[right] = tt;
        
        quickSort(arr, left, lo-1);
        quickSort(arr, lo+1, right);
    }
    
    
    void mergeSort_0103(vector<int> &arr, int low, int hight) {
        if (low >= hight) {
            return;
        }
        int mid = low + (hight - low) / 2;
        mergeSort_0103(arr, low, mid);
        mergeSort_0103(arr, mid + 1, hight);
        merge(arr, low, hight, mid);
    }
    
    void merge_0103(vector<int> &arr, int low, int mid, int hight) {
        
        vector<int> temp;
        int p0 = low;
        int p1 = mid + 1;
        int i = 0;
        while (p0 <= mid && p1 <= hight) {
            if (arr[p0] < arr[p1]) {
                temp[i++] = arr[p0++];
            } else {
                temp[i++] = arr[p1++];
            }
        }
        
        while (p0 <= mid) {
            temp[i++] = arr[p0++];
        }
        
        while (p1 <= hight) {
            temp[i++] = arr[p1++];
        }
        
        for (int i = 0; i < temp.size(); i++) {
            arr[low + i] = temp[i];
        }
    }
    
    void bubbleSort(vector<int> &arr) {
        if (arr.size() <= 1) {
            return;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            bool flag = false;
            // 注意这里是 n-i-1
            for (int j = 0; j < arr.size() - i - 1; j++) {
                if (arr[j] > arr[j+1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                    flag = true;
                }
            }
            
            if (!flag) {
                break;
            }
        }
    }
    
    void insertSort(vector<int> &arr) {
        if (arr.size() <= 1) {
            return;
        }
        
        for (int i = 1; i < arr.size(); i++) {
            int value = arr[i];
            int j = i - 1;
            for (; j >= 0; j--) {
                if (arr[j] > value) {
                    arr[j+1] = arr[j];
                } else {
                    break;
                }
            }
            arr[j+1] = value;
        }
    }
    
    int finkMaxK(vector<int> &arr, int k, int low, int hight) {
        if (low >= hight) {
            return -1;
        }
        
        int i = low;
        int j = hight;
        int tt = arr[low];
        
        while (i < j) {
            while (i < j && arr[j] >= tt) {
                j--;
            }
            
            while (i < j && arr[i] <= tt) {
                i++;
            }
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        int temp = arr[i];
        arr[i] = arr[low];
        arr[low] = temp;
        
        if (i == k) {
            return arr[i];
        } else if (i > k) {
            return finkMaxK(arr, k, low, i - 1);
        } else {
            return finkMaxK(arr, k, i + 1, hight);
        }
    }
};
