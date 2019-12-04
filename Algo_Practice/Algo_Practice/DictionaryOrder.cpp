//
//  DictionaryOrder.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/4.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class DictionaryOrder {
    
public:
    
    int findKthNumber(int n, int k) {
        long p = 1;
        long num = 1;
        while (p < k) {
            long count = genCount(num, n);
            if (p + count > k) {
                num *= 10;
                p++;
            } else if (p+count <= k) {
                num++;
                p += count;
            }
        }
        return num;
    }
    
    long genCount(long prefix, long n) {
        int count = 0;
        for (long a = prefix, b = prefix+1; a <= n; a *= 10, b *= 10) {
            count += min(n+1, b) - a;
        }
        return count;
    }
    
};
