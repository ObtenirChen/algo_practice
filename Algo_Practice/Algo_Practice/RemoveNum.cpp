//
//  RemoveNum.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/6.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class RemoveNum {
    
public:
    
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                count++;
                continue;
            } else {
                nums[k++] = nums[i];
            }
        }
        
        int size = nums.size();
        for (int i = k; i < size; i++) {
            nums.pop_back();
        }
        
        return size - count;
    }
    
};
