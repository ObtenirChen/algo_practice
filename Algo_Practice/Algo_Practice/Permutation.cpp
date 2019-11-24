//
//  Permutation.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/11/24.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Permutation {
    
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        doPermute(nums, 0, result);
        
        return result;
    }
    
    void doPermute(vector<int> &nums, int first, vector<vector<int>> &result) {
        if (first == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = first; i < nums.size(); i++) {
            swap(nums[i], nums[first]);
            doPermute(nums, first+1, result);
            swap(nums[i], nums[first]);
        }
    }
    
};
