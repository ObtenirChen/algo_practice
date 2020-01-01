//
//  KillGame.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2020/1/1.
//  Copyright © 2020 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class KillGame {
    
public:
    
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0 || m == 0) {
            return -1;
        }
        vector<int> child;
        for(int i = 0; i < n; i++) {
            child.push_back(i);
        }
        
        int index = -1;
        while(child.size() > 1) {
            index = (index + m) % child.size();
            vector<int>::iterator it = child.begin() + index;
            child.erase(it);
            index--;
        }
        return child[0];
    }
    
};
