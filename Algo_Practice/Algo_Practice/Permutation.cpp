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
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub = {};
        
        doSubsets(0, sub, result, nums);
        return result;
    }
    
    void doSubsets(int i, vector<int> &sub, vector<vector<int>> &result, vector<int> &nums) {
        result.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) {
                continue;
            }
            sub.push_back(nums[j]);
            doSubsets(j+1, sub, result, nums);
            sub.pop_back();
        }
    }
    
};
