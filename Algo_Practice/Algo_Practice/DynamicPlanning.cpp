//
//  DynamicPlanning.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/2.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class DynamicPlanning {
    
public:
    
    int numPermsDISequence(string S) {
        int n = (int)S.size();
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        
        for (int i = 0; i < n+1; i++) {
            dp[0][i] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (S[i-1] == 'D') {
                    for (int k = j; k < i; k++) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] = dp[i][j] % mod;
                    }
                    
                } else {
                    for (int k = 0; k < j; k++) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] = dp[i][j] % mod;
                    }
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += dp[n][i];
            ans = ans % mod;
        }
        
        return ans;
    }
    
    
    int checkRecord(int n) {
        
        vector<long> result(n < 5 ? 6 : n+1);
        int mod = 1e9 + 7;
        
        result[0] = 1;
        result[1] = 2;
        result[2] = 4;
        result[3] = 7;
        
        for (int i = 4; i <= n; i++) {
            result[i] = ((2 * result[i - 1]) % mod + (mod - result[i - 4])) % mod;
        }
        long sum = result[n];
        for (int i = 1; i <= n; i++) {
            sum += (result[i - 1] * result[n - i]) % mod;
        }
        
        return sum % mod;
    }
    
};
