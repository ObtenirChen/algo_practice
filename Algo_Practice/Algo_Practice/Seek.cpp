//
//  Seek.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/3.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Seek {
    
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int lo = 0, hi = 2 * m;
        int c1, c2, lmax1, lmax2, rmin1, rmin2;
        while (lo <= hi) {
            c1 = (lo + hi) / 2;
            c2 = m+n - c1;
            
            lmax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            rmin1 = (c1 == 2 * m) ? INT_MAX : nums1[c1 / 2];
            lmax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            rmin2 = (c2 == 2 * n) ? INT_MAX : nums2[c2 / 2];
            
            if (lmax1 > rmin2) {
                hi = c1 - 1;
            } else if (lmax2 > rmin1) {
                lo = c1 + 1;
            } else {
                break;
            }
        }
        
        return (max(lmax1, lmax2) + min(rmin1, rmin2)) / 2.0;
    }
    
    
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int lo = 0;
        int hi = (int)nums.size() - 1;
        
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (nums[mid] >= target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
    
    
    int midFind(vector<int> arr, int k) {
        
        int low = 0;
        int hight = (int)arr.size() - 1;
        while (low <= hight) {
            int mid = low + (hight - low) / 2;
            if (arr[mid] == k) {
                return mid;
            } else if (arr[mid] > k) {
                hight = mid - 1;
            } else if (arr[mid] < k) {
                low = mid + 1;
            }
        }
        return -1;
    }
    
    
    // 旋转数组中找最小值
    int finMinNum(vector<int> arr) {
        
        if (arr.empty()) {
            return -1;
        }
        
        int low = 0;
        int hight = (int)arr.size() - 1;
        int mid = 0;
        
        while (arr[low] >= arr[hight]) {
            if (hight - low == 1) {
                return arr[hight];
            }
            
            mid = low + (hight - low) / 2;
            // 三个数相等的情况
            if (arr[mid] == arr[low] && arr[mid] == arr[hight]) {
                int target = arr[low];
                for (int i = low + 1; i <= hight; i++) {
                    if (arr[i] < target) {
                        target = arr[i];
                    }
                }
                return target;
            }
            
            if (arr[mid] >= arr[low]) {
                low = mid;
            }
            
            if (arr[mid] <= arr[hight]) {
                hight = mid;
            }
        }
        return arr[mid];
    }
    
    bool findNumInArr(vector<vector<int>> arr, int num) {
        // 数组记得判空
        if (arr.empty()) {
            return false;
        }
        
        int row = (int)arr.size();
        int col = (int)arr[0].size();
        int i = 0;
        int j = col - 1;
        
        while (i < row && j >= 0) {
            if (arr[i][j] < num) {
                i++;
            } else if (arr[i][j] > num) {
                j--;
            } else {
                return true;
            }
        }
        return false;
    }
    
};
