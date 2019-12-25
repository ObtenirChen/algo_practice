//
//  ZeroOne.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/25.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class ZeroOne {
    
    
public:
    
    int maxValue(vector<int> value, vector<int> wight, int capacity) {
        vector<vector<int>> maxV(value.size() ,vector<int>(capacity+1, 0));
        
        for (int i = 1; i < value.size(); i++) {
            for (int j = 1; j <= capacity; j++) {
                if (j < wight[i]) {
                    maxV[i][j] = maxV[i-1][j];
                } else {
                    maxV[i][j] = max((maxV[i-1][j-wight[i]] + value[i]), maxV[i-1][j]);
                }
            }
        }
        
        return maxV[value.size()-1][capacity];
        
        return 0;
        
    }
    
};
