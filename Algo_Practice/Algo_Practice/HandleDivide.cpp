//
//  HandleDivide.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/12.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class HandleDivide {
    
public:
    
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return 0;
        }
        if (divisor == 1) {
            return dividend;
        } else if (divisor == -1) {
            if (dividend == INT_MIN) {
                return INT_MAX;
            } else {
                return -dividend;
            }
        } else {
            
            int a = dividend > 0 ? dividend : -dividend;
            int b = divisor > 0 ? divisor : -divisor;
            int sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ? -1 : 1;
            int res = doDivide(a, b);
            if (sign == -1) {
                res = -res;
            }
            return res;
        }
    }
    
    int doDivide(int a, int b) {
        
        if (a < b) {
            return 0;
        }
        
        int count = 1;
        int tob = b;
        while (a >= tob + tob) {
            tob = tob + tob;
            count = count + count;
        }
        
        return count + doDivide(a - tob, b);
    }
    
};
