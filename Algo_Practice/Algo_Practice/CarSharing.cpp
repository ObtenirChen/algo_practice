//
//  CarSharing.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/11/24.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class CarSharing {
    
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengers(1001, 0);
        for (int i = 0; i < trips.size(); i++) {
            vector<int> trip = trips[i];
            for (int j = trip[1]; j < trip[2]; j++) {
                if (trip[2] > 1000) {
                    return false;
                }
                passengers[j] += trip[0];
                if (passengers[j] > capacity) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
};
