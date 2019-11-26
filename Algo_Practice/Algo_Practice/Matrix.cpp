//
//  Matrix.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/11/24.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class MyMatrix {
    
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }
        int u = 0;
        int d = (int)matrix.size() - 1;
        int l = 0;
        int r = (int)matrix[0].size() - 1;
        
        while (true) {
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[u][i]);
            }
            u++;
            if (u > d) {
                break;
            }
            for (int i = u; i <= d; i++) {
                ans.push_back(matrix[i][r]);
            }
            r--;
            if (r < l) {
                break;
            }
            for (int i = r; i >= l; i--) {
                ans.push_back(matrix[d][i]);
            }
            d--;
            if (d < u) {
                break;
            }
            for (int i = d; i >= u; i--) {
                ans.push_back(matrix[i][l]);
            }
            l++;
            if (l > r) {
                break;
            }
        }
        
        return ans;
    }
    
};
