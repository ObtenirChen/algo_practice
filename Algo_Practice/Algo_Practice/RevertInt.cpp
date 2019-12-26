//
//  RevertInt.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/26.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

class RevertInt {
    
public:

    int revertIntNum(int num) {
        int a = 0;
        int b = 0;
        while (num != 0) {
            a = num % 10;
            num = num / 10;
            if (b > INT_MAX / 10 || (b == INT_MAX / 10 && a > INT_MAX % 10)) {
                b = 0;
                break;
            } else if (b < INT_MIN / 10 || (b == INT_MIN / 10 && b < INT_MIN % 10)) {
                b = 0;
                break;
            }
            b = b * 10 + a;
        }
        
        return b;
    }
};
