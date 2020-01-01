//
//  CollectionSum.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2020/1/1.
//  Copyright © 2020 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class CollectionSum {
    
    
public:
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> sub;
        vector<vector<int>> result;
        backtrace(candidates, target, 0, sub, result);
        return result;
    }
    
    void backtrace(vector<int> &candidates, int target, int start, vector<int> &sub, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(sub);
            return;
        }
        
        if (target < 0) {
            return;
        }
        
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            sub.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], i, sub, result);
            sub.pop_back();
        }
    }
    
};
