//
//  ColorSort.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2020/1/1.
//  Copyright © 2020 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class ColorSort {
    
public:
    
    void sortColors(vector<int>& nums) {
        
        if (nums.empty()) {
            return;
        }
        
        int p0 = 0;
        int cur = 0;
        int p1 = (int)nums.size() - 1;
        
        while (cur <= p1) {
            if (nums[cur] == 0) {
                swap(nums[cur++], nums[p0++]);
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[p1--]);
            } else {
                cur++;
            }
        }
    }
    
};
