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
    
    
};
