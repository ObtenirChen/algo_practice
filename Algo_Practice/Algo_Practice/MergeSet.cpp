//
//  MergeSet.cpp
//  Algo_Practice
//
//  Created by Obtenir Chen on 2019/12/12.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class MergeSet {
    
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        
        int rightM = intervals[0][1];
        int leftM = intervals[0][0];
        bool needResetL = false;
        for (int i = 1; i < intervals.size(); i++) {
            if (needResetL) {
                rightM = intervals[i][1];
                leftM = intervals[i][0];
            }
            if (intervals[i][0] <= rightM) {
                rightM = max(intervals[i][0], rightM);
            } else {
                vector<int> tem = {leftM, rightM};
                result.push_back(tem);
                needResetL = true;
            }
        }
        vector<int> tem = {leftM, rightM};
        result.push_back(tem);
        
        return intervals;
    }
    
};
