//
//  CalSum.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/5.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class CalSum {
    
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        
        map<int, int> a;
        for (int i = 0; i < nums.size(); i++) {
            if (a.count(target - nums[i]) > 0) {
                result[0] = a[target - nums[i]];
                result[1] = i;
                break;
            } else {
                a[nums[i]] = i;
            }
        }
        
        return result;
    }
    
};
