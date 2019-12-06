//
//  Jump.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/6.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Jump {
    
public:
    
    bool canJump(vector<int>& nums) {
        
        bool ocan = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 && i != nums.size() - 1) {
                bool can = false;
                for (int j = i - 1; j >= 0; j--) {
                    if (nums[j] > i - j) {
                        can = true;
                    }
                }
                
                if (!can) {
                    ocan = false;
                    break;
                }
            }
        }
        
        return ocan;
    }
    
};
