//
//  MergeCollection.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2020/1/1.
//  Copyright © 2020 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class MergeCollection {
    
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) {
            return res;
        }
        
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        int index = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (res[index][1] >= intervals[i][0]) {
                if (res[index][1] < intervals[i][1]) {
                    res[index][1] = intervals[i][1];
                }
            } else {
                index++;
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
    
};
