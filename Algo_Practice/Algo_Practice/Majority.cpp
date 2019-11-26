//
//  Majority.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/11/26.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Majority {
    
    
public:
    
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int sumAns = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                sumAns++;
            } else {
                sumAns--;
            }
            if (sumAns == 0) {
                if (i+1 < nums.size()) {
                    ans =  nums[i+1];
                    i++;
                }
            }
        }
        return ans;
    }
    
};
