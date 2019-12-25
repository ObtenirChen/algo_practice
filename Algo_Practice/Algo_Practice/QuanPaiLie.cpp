//
//  QuanPaiLie.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/25.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class QuanPaiLie {
    
    
public:
    
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        backTrack(nums, 0, result);
        return result;
    }
    
    
    void backTrack(vector<int> &nums, int first, vector<vector<int>> &result) {
        if (first == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = first; i < nums.size(); i++) {
            swap(nums[i], nums[first]);
            backTrack(nums, first+1, result);
            swap(nums[i], nums[first]);
        }
    }
    
    
    vector<vector<int>> subSets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> subs;
        backTrackSubSets(nums, subs, 0, result);
        return result;
    }
    
    void backTrackSubSets(vector<int> &nums, vector<int> &subs, int i, vector<vector<int>> &result) {
        result.push_back(subs);
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1]) {
                continue;
            }
            subs.push_back(nums[j]);
            backTrackSubSets(nums, subs, i+1, result);
            subs.pop_back();
        }
    }
    
};
